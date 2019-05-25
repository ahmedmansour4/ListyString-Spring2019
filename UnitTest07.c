// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest07.c
// =========================
// Test of createListyString().


#include <stdio.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *l1, *l2, *l3;
	int success = 1;

	l1 = createListyString("~ ");
	if (l1->head->data != '~' || l1->head->next->data != ' ' ||
	    l1->head->next->next != NULL || l1->length != 2)
		success = 0;
	l2 = createListyString(NULL);
	if (l2 == NULL || l2->head != NULL || l2->length != 0)
		success = 0;
	l3 = createListyString("");
	if (l3 == NULL || l3->head != NULL || l3->length != 0)
		success = 0;
	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
