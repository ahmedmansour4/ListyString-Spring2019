// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest21.c
// =========================
// Unit test for listyCat(): Test concatenation of a NULL string to an empty
// ListyString.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = 1;

	ListyString *listy;
	ListyString *retval;

	// Create empty string.
	listy = malloc(sizeof(ListyString));
	listy->head = NULL;
	listy->length = 0;

	retval = listyCat(listy, NULL);

	if (listy != retval)
		success = 0;

	if (listy->head != NULL || listy->length != 0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
