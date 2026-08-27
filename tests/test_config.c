/* SPDX-License-Identifier: Apache-2.0 */
#include "config.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

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

static void test_output_options(void)
{
	struct sv_config cfg;
	char *argv[] = {
		"sv-subscriber",
		"--output", "/tmp/results.tsv",
		"--no-prometheus",
	};

	config_set_defaults(&cfg);
	cfg.role = SV_ROLE_SUBSCRIBER;
	assert(cfg.prometheus_enabled == 1);
	assert(config_parse_args(&cfg, 4, argv) == 0);
	assert(cfg.output_path_set == 1);
	assert(strcmp(cfg.output_path, "/tmp/results.tsv") == 0);
	assert(cfg.prometheus_enabled == 0);
}

int main(void)
{
	printf("=== Config Tests ===\n");
	test_live_histogram_options();
	test_output_options();
	printf("All config tests passed.\n");
	return 0;
}
