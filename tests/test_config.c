/* SPDX-License-Identifier: Apache-2.0 */
#include "config.h"

#include <assert.h>
#include <stdio.h>

static void test_live_histogram_options(void)
{
	struct sv_config cfg;
	char *argv[] = {
		"sv-subscriber",
		"--live-histogram",
		"--live-threshold-us",
		"209",
	};

	config_set_defaults(&cfg);
	cfg.role = SV_ROLE_SUBSCRIBER;
	assert(cfg.live_histogram == 0);
	assert(cfg.live_threshold_us == 208);
	assert(config_parse_args(&cfg, 4, argv) == 0);
	assert(cfg.live_histogram == 1);
	assert(cfg.live_threshold_us == 209);
}

int main(void)
{
	printf("=== Config Tests ===\n");
	test_live_histogram_options();
	printf("All config tests passed.\n");
	return 0;
}
