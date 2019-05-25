#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"
// Name: Ahmed Mansour
// NID: ah505081

// This function reads an file and performs actions on a string.
int processInputFile(char *filename)
{
	ListyString *listy = malloc(sizeof(ListyString));
	char *str = malloc(sizeof(char) * 1024);
	char commandChar;
	char keyChar;
	char *strToken;
	FILE *inputFile = fopen(filename, "r");
	
	if (inputFile == NULL)
		return 1;

	fgets(str, 1024, inputFile);
	listy = createListyString(str);
	
	while (fgets(str, 1024, inputFile) != NULL)
	{
		commandChar = strtok(str, " ")[0];
		if (commandChar == '@')
		{
			keyChar = strtok(NULL, " ")[0];
			
			strToken = strtok(NULL, " ");
			replaceChar(listy, keyChar, strToken);
		}
		else if (commandChar == '+')
		{
			strToken = strtok(NULL, " ");
			listyCat(listy, strToken);
		}
		else if (commandChar == '-')
		{
			
			keyChar = strtok(NULL, " ")[0];
			replaceChar(listy, keyChar, "");
		}
		else if (commandChar == '~')
		{
			reverseListyString(listy);
		}
		else if (commandChar == '?')
		{
			printf("%d\n", listyLength(listy));
		}
		else if (commandChar == '!')
		{
			printListyString(listy);
		}
			
			
			
	}
	return 0;
}

// This function creates a ListyString object.
ListyString *createListyString(char *str)
{
	int stringLength = 0;
	ListyString *listy = malloc(sizeof(ListyString));
	ListyNode *node = malloc(sizeof(ListyNode));
	
	if (str == NULL || str == " ")
	{
		listy->head = NULL;
		listy->length = 0;
		return listy;
	}
	
	listy->head = node;
	stringLength = strlen(str) - 1;
	
	for (int i = 0; i < stringLength; i++)
	{
		node->data = str[i];
		node->next = malloc(sizeof(ListyNode));
		node = node->next;
		listy->length++;		
	}
		
	return listy;
}

// This function frees all memory related to the passed ListyString.
ListyString *destroyListyString(ListyString *listy)
{
	if (listy != NULL)
	{
		if (listy->head != NULL)
		{
			free(listy->head);
		}
			free(listy);
	}
	
	return NULL;
}
// This function copies the data from one ListyString to the other entierly seperate ListyString.
ListyString *cloneListyString(ListyString *listy)
{
	ListyNode *node = malloc(sizeof(ListyNode));
	ListyNode *temp = malloc(sizeof(ListyNode));
	ListyString *newListy = malloc(sizeof(ListyString));
	if (listy == NULL)
		return NULL;
	
	if (listy->head == NULL)
	{
		newListy->head = NULL;
	}
		
	newListy->length = listy->length;
	
	temp = listy->head;
	newListy->head = node;
	for (int i = 0; i < listy->length; i++)
	{
		node->data = temp->data;
		node->next = calloc(1, sizeof(ListyNode));
		node = node->next;
		temp = temp->next;
	}
	
	return newListy;
}

// This function takes a given character and replaces all instances of that key in the ListyString with a given string.
void replaceChar(ListyString *listy, char key, char *str)
{
	ListyString *newListy = malloc(sizeof(ListyString));
	ListyNode *temp = malloc(sizeof(ListyNode));
	ListyNode *newTemp = malloc(sizeof(ListyNode));
	int stringLength;
	int listyLength;
	
	if (listy == NULL || listy->head == NULL)
		return;
	
	temp = listy->head;
	newListy->head = newTemp;
	
	if (str == NULL)
		str = "";
	
	stringLength = strlen(str) - 1;
	temp = listy->head;
	newListy->head = newTemp;
	listyLength = listy->length;
	if (stringLength != 0)
	{
		while (temp->next != NULL)
		{
			
			for (int i = 0; i < listyLength; i++)
			{
				if (temp->data == key)
				{
					for (int j = 0; j < stringLength; j++)
					{	
						newTemp->data = str[j];
						newTemp->next = malloc(sizeof(ListyNode));
						newTemp = newTemp->next;
						newListy->length++;
					}
				}
				else
				{
					newTemp->data = temp->data;
					newTemp->next = malloc(sizeof(ListyNode));
					newTemp = newTemp->next;
					newListy->length++;
				}
				temp = temp->next;
			}
		}
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->data != key)
			{
				newTemp->data = temp->data;
				if (temp->next != NULL)
				{
					newTemp->next = malloc(sizeof(ListyNode));
					newTemp = newTemp->next;
					newListy->length++;
				}
				
			}
			temp = temp->next;  
		}
	}
	listy->head = newListy->head;
	listy->length = newListy->length;
	listy = newListy;	
}

// This function reverses the positions of all the data in the ListyString
void reverseListyString(ListyString *listy)
{
	ListyString *newListy = malloc(sizeof(ListyString));
	ListyNode *temp = malloc(sizeof(ListyNode));
	ListyNode *newTemp = malloc(sizeof(ListyNode));
	
	if (listy == NULL || listy->head == NULL)
		return;
	newListy->length = listy->length;
	newListy->head = newTemp;
	
	for (int i = 0; i < newListy->length; i++)
	{
		temp = listy->head;
		while (temp->next->next != NULL && temp->next->data != '\n')
			temp = temp->next;
		newTemp->data = temp->data;
		newTemp->next = malloc(sizeof(ListyNode));
		newTemp = newTemp->next;
		temp->next = NULL;
	}
	listy->head = newListy->head;
	listy = newListy;
}

// This function appends the ListyString with the given string
ListyString *listyCat(ListyString *listy, char *str)
{
	ListyNode *node = malloc(sizeof(ListyNode));
	ListyString *newListy = malloc(sizeof(ListyString));
	int strLength;
	if (listy == NULL && str == NULL)
		return NULL;
	strLength = strlen(str);
	if (listy == NULL && strLength > 0)
		createListyString(str);
	else if (listy == NULL && str == "")
	{
		newListy->head = NULL;
		newListy->length = 0;
		return newListy;
	}
	else if (str != NULL || str != "")
	{
		
		node = listy->head;
		while (node->next != NULL)
			node = node->next;
	
		for (int i = 0; i < strLength; i++)
		{
			node->data = str[i];
			node->next = malloc(sizeof(ListyNode));
			node = node->next;
		}
		listy->length += strLength - 1;
	}
	return listy;
}

// This function compares two strings and checks for any difference
int listyCmp(ListyString *listy1, ListyString *listy2)
{
	int differenceFound = 0;
	ListyNode *node1 = malloc(sizeof(ListyNode));
	ListyNode *node2 = malloc(sizeof(ListyNode));
	if ((listy1 == NULL && listy2 != NULL) || (listy1 != NULL && listy2 == NULL))
		return 1;
	else if (listy1 == NULL && listy2 == NULL)
		return 0;
	else if (listy1->length == 0 && listy2->length == 0)
		return 0;
	node1 = listy1->head;
	node2 = listy2->head;

	while ((node1 != NULL || node2 != NULL) || differenceFound == 1)
	{
		if (node1->data != node2->data)
		{
			differenceFound = 1;
		}
			node1 = node1->next;
			node2 = node2->next;
	}
	if (differenceFound == 1)
		return 1;
	else
		return 0;
}

// This function returns the length of the ListyString
int listyLength(ListyString *listy)
{
	if (listy == NULL)
		return -1;
	else if (listy != NULL && listy->head == NULL)
		return 0;
	else
	return listy->length;
}

// This function prints out all the data held within the ListyString
void printListyString(ListyString *listy)
{
	ListyNode *temp;
	char *str = malloc(sizeof(char) * 1024);
	
	if (listy == NULL || listy->length == 0)
	{
		printf("(empty string)");
	}
	temp = listy->head;
	for (int i = 0; i < listy->length; i++)
	{
		if (temp->data != '\n')
		printf("%c", temp->data); 
		temp = temp->next;
	}
	printf("\n");
}

double difficultyRating(void)
{
	return 4.5;
}

double hoursSpent(void)
{
	return 20.0;
}

int main(int argc, char **argv)
{
	processInputFile(argv[1]);
	return 0;
}
