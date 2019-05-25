// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest24.c
// =========================
// Unit test for listyCmp(): Test the comparison of two NULL pointers.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = 1;

	if (listyCmp(NULL, NULL) != 0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
