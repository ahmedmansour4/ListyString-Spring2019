#ifndef __LISTY_STRING_H
#define __LISTY_STRING_H


// Magic Unit Test Directive

// To run a unit test, you must first uncomment the following #define directive.
// To run a normal test case where your own main function from ListyString.c
// gets called, simply comment out the line with the #define directive again.

// OTHER THAN COMMENTING/UNCOMMENTING THE FOLLOWING LINE, DO NOT MAKE ANY
// MODIFICATIONS TO THIS HEADER FILE!

//#define main __hidden_main__


// Struct Definitions

typedef struct ListyNode
{
	// Each node holds a single character.
	char data;

	// Pointer to next node in linked list.
	struct ListyNode *next;
} ListyNode;


typedef struct ListyString
{
	// Head of the linked list representing this string.
	ListyNode *head;

	// Length of this linked list.
	int length;
} ListyString;


// Functional Prototypes

int processInputFile(char *filename);

ListyString *createListyString(char *str);

ListyString *destroyListyString(ListyString *listy);

ListyString *cloneListyString(ListyString *listy);

void replaceChar(ListyString *listy, char key, char *str);

void reverseListyString(ListyString *listy);

ListyString *listyCat(ListyString *listy, char *str);

int listyCmp(ListyString *listy1, ListyString *listy2);

int listyLength(ListyString *listy);

void printListyString(ListyString *listy);

double difficultyRating(void);

double hoursSpent(void);


#endif
