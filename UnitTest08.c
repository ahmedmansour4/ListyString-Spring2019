// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest08.c
// =========================
// Basic test of destroyListyString(). This does not guarantee memory is being
// freed correctly, but it does check for preventable segmentation faults.


#include <stdio.h>
#include <stdlib.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = 1;
	ListyString *l1;

	l1 = createListyString("Hi");
	l1 = destroyListyString(l1);
	if (l1 != NULL) success = 0;

	l1 = malloc(sizeof(ListyString));
	l1->head = NULL;
	l1->length = 0;
	l1 = destroyListyString(l1);
	if (l1 != NULL) success = 0;

	l1 = NULL;
	l1 = destroyListyString(l1);
	if (l1 != NULL) success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
