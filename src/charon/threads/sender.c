/**
 * @file sender.c
 *
 * @brief Implementation of sender_t.
 *
 */

/*
 * Copyright (C) 2005-2006 Martin Willi
 * Copyright (C) 2005 Jan Hutter
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include <stdlib.h>
#include <pthread.h>

#include "sender.h"

#include <daemon.h>
#include <network/socket.h>
#include <network/packet.h>
#include <queues/send_queue.h>


typedef struct private_sender_t private_sender_t;

/**
 * Private data of a sender_t object.
 */
struct private_sender_t {
	/**
	 * Public part of a sender_t object.
	 */
	 sender_t public;

	 /**
	  * Assigned thread.
	  */
	 pthread_t assigned_thread;

};

/**
 * Implementation of private_sender_t.send_packets.
 */
static void send_packets(private_sender_t * this)
{
	packet_t *current_packet;
	status_t status;
	
	/* cancellation disabled by default */
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

	DBG1(DBG_NET, "sender thread running, thread_ID: %06u",
		 (int)pthread_self());

	while (TRUE)
	{
		current_packet = charon->send_queue->get(charon->send_queue);
		DBG2(DBG_NET, "got a packet, sending it");
		status = charon->socket->send(charon->socket, current_packet);
		if (status != SUCCESS)
		{
			DBG1(DBG_NET, "sending packet failed");
		}
		current_packet->destroy(current_packet);
	}
}

/**
 * Implementation of sender_t.destroy.
 */
static void destroy(private_sender_t *this)
{
	pthread_cancel(this->assigned_thread);
	pthread_join(this->assigned_thread, NULL);
	free(this);
}

/*
 * Described in header.
 */
sender_t * sender_create()
{
	private_sender_t *this = malloc_thing(private_sender_t);

	this->public.destroy = (void(*)(sender_t*)) destroy;

	if (pthread_create(&(this->assigned_thread), NULL, (void*(*)(void*))send_packets, this) != 0)
	{
		free(this);
		charon->kill(charon, "unable to create sender thread");
	}

	return &(this->public);
}
