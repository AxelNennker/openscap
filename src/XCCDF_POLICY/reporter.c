/*
 * Copyright 2014 Red Hat Inc., Durham, North Carolina.
 * All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * Authors:
 *    Šimon Lukašík
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "common/util.h"
//#include "common/list.h"
//#include "common/_error.h"
#include "public/xccdf_policy.h"
#include "reporter_priv.h"

callback_out *reporter_new(char *report_type, void *output_func, void *usr)
{
	callback_out *reporter = oscap_alloc(sizeof(callback_out));
	if (reporter != NULL) {
		reporter->system = report_type;
		reporter->callback = output_func;
		reporter->usr = usr;
	}
	return reporter;
}

int reporter_send_simple(callback_out *reporter, void *data)
{
	return reporter->callback(data, reporter->usr);
}