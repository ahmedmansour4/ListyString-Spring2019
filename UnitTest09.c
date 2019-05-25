// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest09.c
// =========================
// Unit test for replaceChar(): Test the replacement of a single character
// with another single character.


#include <stdio.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int i, length, success = 1;
	char *result = "hullo";

	ListyNode *temp;
	ListyString *listy;

	length = strlen(result);

	listy = createListyString("hello");
	replaceChar(listy, 'e', "u");
printf("bfroe checkr");
fflush(stdout);
	// Check contents of linked list.
	temp = listy->head;
	for (i = 0; i < length; i++)
	{
		printf("temp->data = %c\n", temp->data);
		fflush(stdout);
		if (temp->data != result[i])
			success = 0;
		temp = temp->next;
	}
printf("bfroeddddd checkr");
fflush(stdout);
	// Check for proper NULL termination of linked list.
	if (temp != NULL)
		success = 0;

	// Check length variable.
	if (listy->length != length)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
