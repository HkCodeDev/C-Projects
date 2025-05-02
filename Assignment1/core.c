/*******************************************************************
<assessment name example : Assignment 1 MS - 1 >
Full Name : Hoda Karimi
Student ID# : 138611223
	Email : hkarimi9@myseneca.ca
	Section : NKK
	Authenticity Declaration :
I declare this submission is the result of my own work and has not
been shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ******************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "core.h"


// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing!
	}
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}
// Function to input an integer from the user
int inputInt(void) {
	int inputValue;
	char newLineChar = 'x';
	int valid = 0;

	while (!valid) {
		scanf("%d%c", &inputValue, &newLineChar);

		if (newLineChar == '\n') {
			// Set the flag to exit the loop
			valid = 1;
		}
		else {
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	}

	return inputValue;
}
// Function to input a positive integer from the user
int inputIntPositive(void) {
	int inputValue;
	int positiveInputReceived = 0;

	while (!positiveInputReceived) {
		// Call inputInt to get any integer input
		inputValue = inputInt();

		if (inputValue > 0) {
			// Set the flag to exit the loop
			positiveInputReceived = 1;
		}
		else {
			printf("ERROR! Value must be > 0: ");
		}
	}

	return inputValue;
}
// Function to input an integer within a specified range from the user
int inputIntRange(int lowerBound, int upperBound) {
	int inputValue;
	int invalidInput = 1;

	while (invalidInput) {
		// Call inputInt where it's needed
		inputValue = inputInt();

		if (inputValue < lowerBound || inputValue > upperBound) {
			printf("ERROR! Value must be between %d and %d inclusive: ",
				lowerBound, upperBound);
		}
		else {
			// Set the flag to exit the loop
			invalidInput = 0;
		}
	}

	return inputValue;
}
// Function to input a character from a specified set of options
char inputCharOption(const char* character) {
	char inputValue;
	char newLineChar = 'x';
	int Valid = 0;

	while (!Valid) {
		scanf("%c%c", &inputValue, &newLineChar);

		int i = 0;
		// Flag to check the end of the string (C strings are null-terminated)
		int endOfString = 0;

		while (!endOfString) {
			if (character[i] == '\0') {
				// Set the flag to true if '\0' is encountered
				endOfString = 1;
			}
			else if (inputValue == character[i]) {
				Valid = 1;
			}
			i++;
		}

		if (!Valid) {
			printf("ERROR: Character must be one of [%s]: ", character);
		}
	}

	return inputValue;
}

// Function to input a string within a specified length range
void inputCString(char* cString, int minimum, int maximum) {
	int i, size = 0;
	// Flag to indicate whether the input is invalid initially
	int invalidInput = 1;

	// Ensure the array is large enough to accommodate the maximum length
	char tempArray[MEMORY];

	while (invalidInput) {
		// Use tempArray for input to avoid overwriting string in case of invalid input
		scanf(" %[^\n]%*c", tempArray);

		size = 0;
		for (i = 0; tempArray[i] != '\0'; i++) {
			size++;
		}

		if (size < minimum || size > maximum) {
			// Set the flag to indicate invalid input
			invalidInput = 1;

			if (minimum == maximum) {
				printf("ERROR: String length must be exactly %d chars: ",
					minimum);
			}
			else if (size > maximum) {
				printf("ERROR: String length must be no more than %d chars: ",
					maximum);
			}
			else {
				printf("ERROR: String length must be between %d and %d "
					"chars: ", minimum, maximum);
			}
		}
		else {
			// Reset the flag as the input is valid
			invalidInput = 0;
		}
	}

	// Manually copy characters to the output parameter
	for (i = 0; i <= size; i++) {
		cString[i] = tempArray[i];
	}
	// Null-terminate the string
	cString[size] = '\0';
}
// Function to display a formatted phone number
void displayFormattedPhone(const char* cString) {
	int i;
	if (cString != NULL) {
		int size = strlen(cString);
		int allDigits = 1;

		for (i = 0; i < size && allDigits; i++) {
			if (cString[i] < '0' || cString[i] > '9') {
				allDigits = 0;
			}

			// Check for the conditions that would make the phone number invalid
			if (size > 10) {
				allDigits = 0;
			}
		}

		if (size != 10 || !allDigits) {
			printf("(___)___-____");
		}
		else {
			printf("(");
			for (i = 0; i < 3; i++) {
				printf("%c", cString[i]);
			}
			printf(")");

			for (i = 3; i < 6; i++) {
				printf("%c", cString[i]);
			}

			printf("-");

			for (i = 6; i < 10; i++) {
				printf("%c", cString[i]);
			}
		}
	}
	else {
		printf("(___)___-____");
	}
}