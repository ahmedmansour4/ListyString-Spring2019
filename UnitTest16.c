// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest16.c
// =========================
// Unit test for reverseListyString(): Test the reversal of an empty string.
// This essentially just checks whether there is a preventable segfault.


#include <stdio.h>
#include <stdlib.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = 1;

	// Set up an empty string.
	ListyString *listy = malloc(sizeof(ListyString));
	listy->head = NULL;
	listy->length = 0;

	reverseListyString(listy);

	if (listy->head != NULL || listy->length != 0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
