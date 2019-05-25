// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest15.c
// =========================
// Unit test for reverseListyString(): Test the reversal of a NULL pointer. This
// essentially just checks whether there is a preventable segfault.


#include <stdio.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = 1;
	reverseListyString(NULL);

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
