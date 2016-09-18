/* packet-bpep.c
 * Routines for BM2E Proprietary Ethernet protocol packet disassembly
 * By Thomas Venries <thomas.venries@gmail.com>
 * Copyright 2000 Thomas Venries
 *
 * Wireshark – Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place – Suite 330, Boston, MA 02111-1307, USA.
 */

#include "config.h"

#include <epan/packet.h>

#include "packet-bpep.h"

#define BPEP_UDP_PORT 1234

static int proto_bpep = -1;
static int hf_bpep_pdu_type = -1;
static gint ett_bpep = -1;

static int dissect_bpep(tvbuff_t *tvb,
		packet_info *pinfo,
		proto_tree * tree _U_,
		void *data _U_)
{
	col_set_str(pinfo->cinfo, COL_PROTOCOL, "BPEP");
	/* Clear out stuff in the info column */
	col_clear(pinfo->cinfo, COL_INFO);

	return tvb_captured_length(tvb);
}

void proto_register_bpep(void)
{
	static hf_register_info hf[] = {
		{ &hf_bpep_pdu_type,
			{ "BPEP PDU Type", "bpep.type",
				FT_UINT8, BASE_DEC,
				NULL, 0x0,
				NULL, HFILL
			}
		}
	};

	/* Setup protocol subtree array */
	static gint *ett[] = {
		&ett_bpep
	};

	/* Register the protocol name and description */
	proto_bpep = proto_register_protocol(
			"BM2E Proprietarty Ethernet Protocol",
			"BPEP",
			"bpep"
			);

	proto_register_field_array(proto_bpep, hf, array_length(hf));
	proto_register_subtree_array(ett, array_length(ett));
}

void proto_reg_handoff_bpep(void)
{
	static dissector_handle_t bpep_handle;

	bpep_handle = create_dissector_handle(dissect_bpep, proto_bpep);
	dissector_add_uint("udp.port", BPEP_UDP_PORT, bpep_handle);
}
