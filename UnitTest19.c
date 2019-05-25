// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest19.c
// =========================
// Unit test for listyCat(): Test concatenation of a non-empty string to an
// empty ListyString.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int i, length, success = 1;
	char *result = "Hewwo!";

	ListyNode *temp;
	ListyString *listy;
	ListyString *retval;

	length = strlen(result);

	// Create empty string.
	listy = malloc(sizeof(ListyString));
	listy->head = NULL;
	listy->length = 0;

	retval = listyCat(listy, "Hewwo!");

	if (listy != retval)
		success = 0;

	// Check contents of linked list.
	temp = listy->head;
	for (i = 0; i < length; i++)
	{
		if (temp->data != result[i])
			success = 0;
		temp = temp->next;
	}

	// Check for proper NULL termination of linked list.
	if (temp != NULL)
		success = 0;

	// Check length variable.
	if (listy->length != length)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
