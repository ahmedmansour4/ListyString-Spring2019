// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest31.c
// =========================
// Quick check to ensure that processInputFile() returns 1 when it fails to
// find the specified input file.


#include <stdio.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = processInputFile("__NO_FILE_BY_THIS_NAME_SHOULD_EXIST__");
	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
