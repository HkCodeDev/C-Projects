/*****************************************************************************
<assessment name example : Workshop - #4 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
	Email : hkarimi9@myseneca.ca
	Section : NKK
	Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/ 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {

	char loopType;
	int numIterations;
	int i;
	printf("+----------------------+\n"); 
	printf("Loop application STARTED\n");
	printf("+----------------------+\n\n");
	
	do {
		printf("D = do/while | W = while | F = for | Q = quit\n");
		printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
		scanf(" %c%d", &loopType, &numIterations);

		if (loopType == 'Q' && numIterations == 0) 
		{
			printf("\n+--------------------+\n");
			printf("Loop application ENDED\n");
			printf("+--------------------+\n");
		}
		else if (loopType == 'Q' && numIterations != 0)
		{
			printf("ERROR: To quit, the number of iterations should be 0!\n\n");
		}
		
		else if (loopType != 'D' && loopType != 'W' && loopType != 'F') 
		{
			printf("ERROR: Invalid entered value(s)!\n\n");
		}

		else if (numIterations < 3 || numIterations > 20) 
		{
			printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
	
		}
		else
		{
			if (loopType == 'D') 
			{
				printf("DO-WHILE: ");
				do {
					printf("D");
					numIterations--;
				} while (numIterations > 0);
				printf("\n");
			} 
			else if (loopType == 'W') 
			{
				printf("WHILE   : ");
				while (numIterations > 0) 
				{
					printf("W");
					numIterations--;
				} printf("\n");
			} 
			else if (loopType == 'F') 
			{
				printf("FOR     : ");
				for (i = 0; i < numIterations; i++)
				{
					printf("F");
				}printf("\n"); 
			}
			printf("\n");
		}
		} while (!(loopType == 'Q' && numIterations == 0));
		return 0;
	} 