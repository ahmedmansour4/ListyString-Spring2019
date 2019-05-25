// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest29.c
// =========================
// Unit test for printListyString(): Test the printing of a ListyString.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *listy = createListyString("monarch");

	printListyString(listy);
	printf("Length: %d\n", listyLength(listy));

	return 0;
}
