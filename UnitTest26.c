// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest26.c
// =========================
// Unit test for listyCmp(): Test the comparison of a NULL pointer to an empty
// string.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = 1;

	ListyString *listy;

	// Create an empty string.
	listy = malloc(sizeof(ListyString));
	listy->head = NULL;
	listy->length = 0;

	if (listyCmp(listy, NULL) == 0)
		success = 0;

	if (listyCmp(NULL, listy) == 0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
