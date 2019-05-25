// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest25.c
// =========================
// Unit test for listyCmp(): Test the comparison of two empty strings.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = 1;

	ListyString *listy1, *listy2;

	// Create an empty string.
	listy1 = malloc(sizeof(ListyString));
	listy1->head = NULL;
	listy1->length = 0;

	// Create another empty string.
	listy2 = malloc(sizeof(ListyString));
	listy2->head = NULL;
	listy2->length = 0;

	if (listyCmp(listy1, listy2) != 0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
