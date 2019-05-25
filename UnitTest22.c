// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest22.c
// =========================
// Unit test for listyCmp(): Test the comparison of two equivalent, non-empty
// strings.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = 1;

	ListyString *listy1, *listy2;

	// Manually create a listy string. This is awful.
	listy1 = malloc(sizeof(ListyString));
	listy1->head = malloc(sizeof(ListyNode));
	listy1->head->next = malloc(sizeof(ListyNode));
	listy1->head->next->next = malloc(sizeof(ListyNode));
	listy1->head->next->next->next = NULL;
	listy1->head->data = 'c';
	listy1->head->next->data = 'a';
	listy1->head->next->next->data = 't';
	listy1->length = 3;

	// Manually create another listy string. This is awful.
	listy2 = malloc(sizeof(ListyString));
	listy2->head = malloc(sizeof(ListyNode));
	listy2->head->next = malloc(sizeof(ListyNode));
	listy2->head->next->next = malloc(sizeof(ListyNode));
	listy2->head->next->next->next = NULL;
	listy2->head->data = 'c';
	listy2->head->next->data = 'a';
	listy2->head->next->next->data = 't';
	listy2->length = 3;

	if (listyCmp(listy1, listy2) != 0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
