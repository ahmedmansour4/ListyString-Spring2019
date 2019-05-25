// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest30.c
// =========================
// Unit test for printListyString(): Test the printing of a manually created
// ListyString.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	// Manually create a listy string. This is gross, but it helps ensure that
	// the function works with a properly constructed ListyString.
	ListyString *listy = malloc(sizeof(ListyString));
	listy->head = malloc(sizeof(ListyNode));
	listy->head->next = malloc(sizeof(ListyNode));
	listy->head->next->next = malloc(sizeof(ListyNode));
	listy->head->next->next->next = malloc(sizeof(ListyNode));
	listy->head->next->next->next->next = malloc(sizeof(ListyNode));
	listy->head->next->next->next->next->next = malloc(sizeof(ListyNode));
	listy->head->next->next->next->next->next->next = malloc(sizeof(ListyNode));
	listy->head->next->next->next->next->next->next->next = NULL;
	listy->head->data = 'm';
	listy->head->next->data = 'o';
	listy->head->next->next->data = 'n';
	listy->head->next->next->next->data = 'a';
	listy->head->next->next->next->next->data = 'r';
	listy->head->next->next->next->next->next->data = 'c';
	listy->head->next->next->next->next->next->next->data = 'h';
	listy->length = 7;

	printListyString(listy);
	printf("Length: %d\n", listyLength(listy));

	return 0;
}
