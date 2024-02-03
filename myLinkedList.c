#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "myLinkedList.h"

/*************************************************
* Function Title: addNodeToList
*
* Summary: adds a node into a sorted linked list without duplicating values
*
* Inputs: first, a pointer to the first element of the linked list, 
			val, the val that is being added to the linked list
* Outputs: the new first element of the list, possibly unchanged
*
* Compile instructions: use makefile
**************************************************
* Pseudocode
*
* Begin
*	create a new struct node (malloc)
	check for success
	store val in node
	find vals place in list
	check if val is a duplicate value
	set new_node's next pointer to next in list
	If new_node is first in list
		set first = new_node;
	Else
		set previous node's next pointer to new_node
	EndIf
	return first
	
* End
*************************************************/

struct node *addNodeToList(struct node *first, int val)
{//Begin
	//create a new struct node (malloc)
	struct node *new_node, *cur, *prev;
	new_node = malloc(sizeof(struct node)); 
	//check for success
	if (new_node == NULL) {
		printf("Database is full; can't add more parts.\n"); 
		exit(1);
	}

	//store val in node
	new_node->val = val;

	//find vals place in list
	for (cur = first, prev = NULL;
		cur != NULL && new_node->val > cur->val; 
		prev = cur, cur = cur->next)
	;

	//check if val is a duplicate value
	if (cur != NULL && new_node->val == cur->val) 
	{
		free(new_node); 
	} else {

	//set new_node's next pointer to next in list
	new_node->next = cur;
	
	//If new_node is first in list
	if (prev == NULL)
		first = new_node; 
	else
		//set previous node's next pointer to new_node
		prev->next = new_node;
	} //EndIf
	
	//return first
	return first;
} //End

/*************************************************
* Function Title: printList
*
* Summary: prints a table of square, cubic, and fourth roots to a file for each
			element of a linked list
*
* Inputs: first: a pointer to the first element of the linked list, 
			f: pointer to the output file
* Outputs: none
*
* Compile instructions: use makefile
**************************************************
* Pseudocode
*
* Begin
*	start pointer at front of list
	Loop until end of list
		print value + roots to filelength
	EndLoop
* End
*************************************************/
void printList(struct node *first, FILE *f) 
{ //Begin
	//start pointer at front of list
	struct node *p;
	//Loop until end of list
	for (p = first; p != NULL; p = p->next)
	{
		//print value + roots to filelength
		fprintf(f, "%d\t%.3f\t%.3f\t%.3f\n", p->val, sqrt(((double)p->val)), cbrt(((double)p->val)), pow(((double)p->val), 1.0/4.0));
	}//EndLoop
	
}//End