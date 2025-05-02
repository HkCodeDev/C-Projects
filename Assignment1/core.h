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
#ifndef CORE_H  
#define CORE_H
#define _CRT_SECURE_NO_WARNINGS
#define MEMORY 100
#include <stdio.h>

void clearInputBuffer(void);
void suspend(void);
// Function to input an integer from the user
int inputInt(void);
// Function to input a positive integer from the user
int inputIntPositive(void);
// Function to input an integer within a specified range from the user
int inputIntRange(int lowerBound, int upperBound);
// Function to input a character from a specified set of options
char inputCharOption(const char* character);
// Function to input a string within a specified length range
void inputCString(char* cString, int minimum, int maximum);
// Function to display a formatted phone number
void displayFormattedPhone(const char* cString);
#endif


