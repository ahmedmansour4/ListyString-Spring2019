// Sean Szumlanski
// COP 3502, Spring 2019

// =========================
// ListyString: UnitTest06.c
// =========================
// Boundary checks to help ensure the difficultyRating() and hoursSpent()
// functions are implemented correctly.


#include <stdio.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int success = 1;

	if (difficultyRating() < 1.0 || difficultyRating() > 5.0)
		success = 0;
	if (hoursSpent() <= 0.0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
