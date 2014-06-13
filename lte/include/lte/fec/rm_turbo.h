/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2014 The libLTE Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution.
 *
 * \section LICENSE
 *
 * This file is part of the libLTE library.
 *
 * libLTE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * libLTE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * A copy of the GNU Lesser General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */


#ifndef RM_TURBO_
#define RM_TURBO_

#include "lte/config.h"

#ifndef RX_NULL
#define RX_NULL 10000
#endif

#ifndef TX_NULL
#define TX_NULL 80
#endif

typedef struct LIBLTE_API {
	int buffer_len;
	char *buffer;
	int *d2_perm;
} rm_turbo_t;

LIBLTE_API int rm_turbo_init(rm_turbo_t *q, int max_codeblock_len);
LIBLTE_API void rm_turbo_free(rm_turbo_t *q);
LIBLTE_API int rm_turbo_tx(rm_turbo_t *q, char *input, int in_len, char *output, int out_len, int rv_idx);
LIBLTE_API int rm_turbo_rx(rm_turbo_t *q, float *input, int in_len, float *output, int out_len, int rv_idx);


/* High-level API */
typedef struct LIBLTE_API {
	rm_turbo_t q;
	struct rm_turbo_init {
		int direction;
	} init;
	void *input;			// input type may be char or float depending on hard
	int in_len;
	struct rm_turbo_ctrl_in {
		int E;
		int S;
		int rv_idx;
	} ctrl_in;
	void *output;
	int out_len;
}rm_turbo_hl;

LIBLTE_API int rm_turbo_initialize(rm_turbo_hl* h);
LIBLTE_API int rm_turbo_work(rm_turbo_hl* hl);
LIBLTE_API int rm_turbo_stop(rm_turbo_hl* hl);

#endif
