/*
 * Copyright (C) 2011 Andreas Steffen
 * HSR Hochschule fuer Technik Rapperswil
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

/**
 * @defgroup pts_component pts_component
 * @{ @ingroup pts
 */

#ifndef PTS_COMPONENT_H_
#define PTS_COMPONENT_H_

typedef struct pts_component_t pts_component_t;

#include "pts/pts.h"
#include "pts/pts_database.h"
#include "pts/components/pts_comp_func_name.h"
#include "pts/components/pts_comp_evidence.h"

#include <library.h>

/**
 * PTS Functional Component Interface 
 */
struct pts_component_t {

	/**
	 * Get the PTS Component Functional Name
	 *
	 * @return				PTS Component Functional Name
	 */
	pts_comp_func_name_t* (*get_comp_func_name)(pts_component_t *this);

	/**
	 * Get the PTS Component Evidence Flags
	 *
	 * @return				PTS Component Functional Name
	 */
	u_int8_t (*get_evidence_flags)(pts_component_t *this);

	/**
	 * Get the PTS Sub-component Depth
	 *
	 * @return				PTS Sub-component Depth
	 */
	u_int32_t (*get_depth)(pts_component_t *this);

	/**
	 * Do evidence measurements on the PTS Functional Component
	 *
	 * @param pts			PTS interface
	 * @param evidence		returns component evidence measureemt
	 * @return				status return code
	 */
	status_t (*measure)(pts_component_t *this, pts_t *pts,
						pts_comp_evidence_t** evidence);

	/**
	 * Verify the evidence measurements of the PTS Functional Component
	 *
	 * @param pts			PTS interface
	 * @param pts_db		PTS measurement database
	 * @param evidence		component evidence measurement to be verified
	 * @return				status return code
	 */
	status_t (*verify)(pts_component_t *this, pts_t *pts,
					   pts_database_t *pts_db,
					   pts_comp_evidence_t *evidence);

	/**
	 * Destroys a pts_component_t object.
	 */
	void (*destroy)(pts_component_t *this);

};

#endif /** PTS_COMPONENT_H_ @}*/
