/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson1984@gmail.com>
 *
 * Licensed under the LGPL v2.1, see the file COPYING in base directory.
 */

#include <stdio.h>
#include "zlog.h"

int main(int argc, char** argv)
{
	int rc;

	rc = zlog_init("test_add_rule.conf");
	if (rc) {
		printf("init failed\n");
		return -1;
	}

	zlog_add_format("simple = \"this is my _cat %m%n\"");
	zlog_add_rule("my_cat.*    \"test_add_rule.log\", 100MB * 32 ; simple");

	dzlog_set_category("my_cat");

	dzlog_info("hello, zlog");

	zlog_fini();
	
	return 0;
}
