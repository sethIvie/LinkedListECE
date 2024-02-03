/*************************************************
* Function Title: Main
*
* Summary: gets two files from command line, it will take ints from th first,
*  then make a sorted table of the square, cubic and fourth roots of those ints
*
* Inputs: none
* Outputs: none
*
* Compile instructions: use makefile
**************************************************
* Pseudocode
*
* Begin
*	if there are not 3 comand line arguments
*	Then
*		print error message
*	Else
*		open input file (check for success)
*		open output file (check for success)
*		set list pointer to NULL
*		Loop until end of input file
*			read integer from input file
*			add integer to sorted list with no duplicates
*		EndLoop
*		close input file
*		print values to output file
*		close output file
*		free memory
*	EndIf
* End
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "myLinkedList.h"

int main(int argc, char *argv[])
{ //Begin
	//if there are not 3 comand line arguments
	if (argc < 3){
		//print error message
		printf("Does not have 3 command line arguments");
		exit(1);
	} else {
		
		FILE *inputFile, *outputFile;
		//open input file (check for success)
		inputFile = fopen(argv[1], "r");
		if(!inputFile)
		{
			printf("Could not open %s", argv[1]);
			exit(1);
		}
		//open output file (check for success)
		outputFile = fopen(argv[2], "w");
		if(!outputFile)
		{
			printf("Could not open %s", argv[2]);
			exit(1);
		}
		//set list pointer to NULL
		struct node *list = NULL;
		
		int num;
		//Loop until end of input file
		while (!feof(inputFile))
		{
			//read integer from input file
			if(fscanf(inputFile, "%d", &num) == 1)
			{
				//add integer to sorted list with no duplicates
				list = addNodeToList(list, num);
			}
		}//EndLoop
		//close input file
		fclose(inputFile);
		//print values to output file
		printList(list, outputFile);
		//close output file
		fclose(outputFile);
		
		//free memory
		struct node *p, *prev = NULL;
		for (p = list; p != NULL; p = p->next)
		{
			if (prev != NULL){
				free(prev);
				prev = p;
			} else {
				prev = p;
			}
		}
		
	} //EndIf
} //End