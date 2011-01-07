/*
 * Copyright (C) 2006 Mike McCauley (mikem@open.com.au)
 * Copyright (C) 2010 Andreas Steffen, HSR Hochschule fuer Technik Rapperswil
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

#include "tnccs_reason_strings_msg.h"

#include <debug.h>

typedef struct private_tnccs_reason_strings_msg_t private_tnccs_reason_strings_msg_t;

/**
 * Private data of a tnccs_reason_strings_msg_t object.
 *
 */
struct private_tnccs_reason_strings_msg_t {
	/**
	 * Public tnccs_reason_strings_msg_t interface.
	 */
	tnccs_reason_strings_msg_t public;

	/**
	 * TNCCS message type
	 */
	tnccs_msg_type_t type;

	/**
	 * XML-encoded message node
	 */
	xmlNodePtr node;

	/**
	 * Reason Language
	 */
	char* language;

	/**
	 * Reason String
	 */
	char* reason;
};

METHOD(tnccs_msg_t, get_type, tnccs_msg_type_t,
	private_tnccs_reason_strings_msg_t *this)
{
	return this->type;
}

METHOD(tnccs_msg_t, get_node, xmlNodePtr,
	private_tnccs_reason_strings_msg_t *this)
{
	return this->node;
}

METHOD(tnccs_msg_t, destroy, void,
	private_tnccs_reason_strings_msg_t *this)
{
	free(this->language);
	free(this->reason);
	free(this);
}

METHOD(tnccs_reason_strings_msg_t, get_reason, char*,
	private_tnccs_reason_strings_msg_t *this, char **language)
{
	*language = this->language;

	return this->reason;
}

/**
 * See header
 */
tnccs_msg_t *tnccs_reason_strings_msg_create_from_node(xmlNodePtr node)
{
	private_tnccs_reason_strings_msg_t *this;

	INIT(this,
		.public = {
			.tnccs_msg_interface = {
				.get_type = _get_type,
				.get_node = _get_node,
				.destroy = _destroy,
			},
			.get_reason = _get_reason,
		},
		.type = TNCCS_MSG_REASON_STRINGS,
		.node = node,
	);

	return &this->public.tnccs_msg_interface;
}

/**
 * See header
 */
tnccs_msg_t *tnccs_reason_strings_msg_create(char *language, char *reason)
{
	private_tnccs_reason_strings_msg_t *this;
	xmlNodePtr n, n2, n3;

	INIT(this,
		.public = {
			.tnccs_msg_interface = {
				.get_type = _get_type,
				.get_node = _get_node,
				.destroy = _destroy,
			},
			.get_reason = _get_reason,
		},
		.type = TNCCS_MSG_REASON_STRINGS,
		.node =  xmlNewNode(NULL, BAD_CAST "TNCC-TNCS-Message"),
		.language = strdup(language),
		.reason = strdup(reason),
	);

	/* add the message type number in hex */
	n = xmlNewNode(NULL, BAD_CAST "Type");
	xmlNodeSetContent(n, BAD_CAST "00000004");
	xmlAddChild(this->node, n);

	n = xmlNewNode(NULL, BAD_CAST "XML");
	xmlAddChild(this->node, n);

	n2 = xmlNewNode(NULL, BAD_CAST enum_to_name(tnccs_msg_type_names, this->type));
	xmlNodeSetContent(n2, BAD_CAST language);
	xmlAddChild(n, n2);

    /* could add multiple reasons here, if we had them */
    n3 = xmlNewNode(NULL, BAD_CAST "ReasonString");
    xmlNewProp(n3, BAD_CAST "xml:lang", BAD_CAST language);
    xmlNodeSetContent(n3, BAD_CAST reason);
    xmlAddChild(n2, n3);

	return &this->public.tnccs_msg_interface;
}
