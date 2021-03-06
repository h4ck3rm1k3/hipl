/*
 * esp_prot_defines.h
 *
 *  Created on: 07.04.2009
 *      Author: chilli
 */

#ifndef ESP_PROT_DEFINES_H_
#define ESP_PROT_DEFINES_H_

#include "hashchain.h"

/* defines the default tolerance when verifying hash-chain elements
 *
 * @note set to the preferred anti-replay window size of ESP */
#define DEFAULT_VERIFY_WINDOW 			64
/* if unused hchain element count of the active_hchain falls below
 * this threshold (% of max count), it will trigger the setup of
 * a new next_hchain */
#define REMAIN_HASHES_TRESHOLD			0.5

// switch to use parallel hchains for authentication
#define PARALLEL_HCHAINS_MODE			0
/* the number of parallel hash chain to be used
 * when parallel hash chain authentication is active
 */
#define NUM_PARALLEL_HCHAINS			6

// switch to use cumulative authentication TPA
#define CUMULATIVE_AUTH_MODE			0
/* size of the buffer for cumulative authentication
 *
 * NOTE: should not be set higher than IPsec replay window
 * 		 -> packet would be dropped anyway then
 */
#define RINGBUF_SIZE					64
#define NUM_LINEAR_ELEMENTS				1
#define NUM_RANDOM_ELEMENTS				0



/* as using different hchain lengths for bex is not supported in esp_prot,
 * we can set a default length statically */
#define DEFAULT_HCHAIN_LENGTH_ID	0
 /* for update_hchain_lengths[] */
#define NUM_UPDATE_HCHAIN_LENGTHS	1
/* number of hierarchies used to link hchains in the BEX store */
#define NUM_BEX_HIERARCHIES			1
/* number of hierarchies used to link hchains in the update store */
#define NUM_UPDATE_HIERARCHIES		4


/* packet information required by the cumulative authentication of TPA */
struct esp_cumulative_item
{
	uint32_t seq; /* current sequence of the IPsec SA */
	unsigned char packet_hash[MAX_HASH_LENGTH];
} __attribute__ ((packed));

typedef struct esp_cumulative_item esp_cumulative_item_t;

#endif /* ESP_PROT_DEFINES_H_ */
