
/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Hoda Karimi
Student ID#: 138611223
Email      : hkarimi9@myseneca.ca
Section    : NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}
// ---------------------------------------------------------------------------// 
// !!! Put all the remaining function definitions below !!!// 
// Note: Maintain the same order/sequence as it is listed in the header file// 
// --------------------------------------------------------------------------

void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    // Display table header if the format is a table
    
    if (fmt == FMT_TABLE) {
        displayPatientTableHeader();
    }

    // Message to be displayed when no records are found
    char noRecordsMessage[] = "*** No records found ***\n\n";
    // Flag to check if there are any records
    int hasRecords = 0;
    int i;
   

    // Loop through all patients
    for ( i = 0; i < max; i++) {
        // Check if the patient has a valid patient number
        if (patient[i].patientNumber != 0) {
            // Display patient data based on the specified format
            displayPatientData(&patient[i], fmt); 
            hasRecords = 1; 
        }
    }

    // If no records are found, print the no records message
    if (!hasRecords) {
        for (i = 0; i < strlen(noRecordsMessage); i++) {
            putchar(noRecordsMessage[i]);
        }
    }
    else {
        // Print a newline if there are records to separate them from the message
        printf("\n");
    }
}
// Search for a patient record based on patient number or phone number// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientData(const struct Patient patient[], int max) {
    int selection;    // User's menu selection
    int flag = 1;  // Set to 1 initially to enter the loop

    // Main loop for searching patient data
    do {
        // Display search options menu
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");

        // Read user's menu selection
        scanf("%d", &selection); 
        printf("\n");

        // Switch statement to perform actions based on user's selection
        switch (selection) {
        case 1:
            // Search by patient number
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();  // Clear input buffer to prevent unexpected behavior
            suspend();           // Pause execution, waiting for user input
            break;
        case 2:
            // Search by phone number
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();  // Clear input buffer to prevent unexpected behavior
            suspend();           // Pause execution, waiting for user input
            break;
        case 0:
            // Set flag to 0 to exit the loop and return to the previous menu
            flag = 0;
            break;
        }

    } while (flag);  // Continue the loop as long as the flag is true
}
void addPatient(struct Patient patient[], int max) {
    int existingRecord = 0;  // Variable to track the number of existing patient records

    // Loop through the patient array to find the number of existing patient records
    int i;
    for (i = 0; i < max && patient[i].patientNumber != 0; i++) {
        existingRecord++;  
    }

    // Check if there is space available for a new patient record
    if (max > existingRecord) {  
        int index = existingRecord;  // Index for the new patient record
        patient[index].patientNumber = nextPatientNumber(patient, max);  // Assign the next patient number
        inputPatient(&patient[index]);  // Input patient data for the new record
        printf("*** New patient record added ***\n\n");
        clearInputBuffer();  // Clear input buffer to prevent unexpected behavior
    }
    else {
        // Display an error message if the patient listing is full
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}
// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {
    int patientNum;
    int index;  // Variables to store user-inputted patient number and the index of the patient in the array

    // Prompt the user to enter the patient number
    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    printf("\n");

    // Find the index of the patient in the array based on the entered patient number
    index = findPatientIndexByPatientNum(patientNum, patient, max);

    // Check if the patient record is found within the array bounds
    if (index >= 0 && index < max) {
        // Invoke the menuPatientEdit function to edit the patient's information
        menuPatientEdit(&patient[index]);
    }
    else {
        // Display an error message if the patient record is not found
        printf("ERROR: Patient record not found!\n");
    }
} 
// Remove a patient record from the patient array// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
    int patientNum; 
    int index;  // Variables to store user-inputted patient number and the index of the patient in the array
    char selection;  // Variable to store user's choice for removing the patient record

    // Prompt the user to enter the patient number
    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    printf("\n");

    // Find the index of the patient in the array based on the entered patient number
    index = findPatientIndexByPatientNum(patientNum, patient, max); 

    // Check if the patient record is found within the array bounds
    if (index >= 0 && index < max) {
        // Display patient information for confirmation
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");

        // Prompt the user for confirmation to remove the patient record
        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &selection);

        // Switch statement to handle user's choice
        switch (selection) {
        case 'n':
        case 'N':
            // Operation aborted, display message and clear input buffer
            printf("Operation aborted.\n\n");
            clearInputBuffer();
            break;
        case 'y':
        case 'Y':
            // Remove the patient record by setting patient number to 0
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
            break;
        }
    }
    else {
        // Display an error message if the patient record is not found
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}
//////////////////////////////////////// UTILITY FUNCTIONS//////////////////////////////////////
// // Search and display patient record by patient number (form)
// // (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int index; 
    int patientNum;    // Variables to store user-inputted patient number and the index of the patient in the array

    // Prompt the user to enter the patient number
    printf("Search by patient number: ");
    scanf("%d", &patientNum);
    printf("\n");

    // Check if the patient record exists in the array using the findPatientIndexByPatientNum function
    int conditionResult = (findPatientIndexByPatientNum(patientNum, patient, max) >= 0);

    // Switch statement based on the condition result
    switch (conditionResult) {
    case 1:
        // Display patient information if the patient record is found
        index = findPatientIndexByPatientNum(patientNum, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)\n\n", patient[index].phone.description);
        break;
    default:
        // Display a message if no records are found
        printf("*** No records found ***\n\n");
    }
}
    // Search and display patient records by phone number (tabular)
    // // (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int c;
    int index = 0;
    int continueReading = 1;
    int match = 0;   // Variables to iterate through the array and count matching records
    char phoneNum[PHONE_LEN + 1];  // Array to store user-inputted phone number
    clearInputBuffer();  // Clear input buffer to prevent unexpected behavior

    // Prompt the user to enter the phone number
    printf("Search by phone number: ");

    // Read characters until a newline or end of file is encountered, storing them in the phoneNumber array


    while (index < PHONE_LEN && continueReading) {
        c = getchar();
        continueReading = (c != '\n' && c != EOF);
        if (continueReading) {
            phoneNum[index++] = (char)c;
        }
    }

    phoneNum[index] = '\0';  // Null-terminate the phoneNumber array

    printf("\n");
    displayPatientTableHeader();  // Display the table header for patient information

    // Iterate through the patient array to find matching records based on phone number
    int i;
    for (i = 0; i < max + 1; i++) {
        // Switch statement based on the result of comparing phone numbers
        switch (strcmp(patient[i].phone.number, phoneNum)) {
        case 0:
            // Display patient information if the phone numbers match
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            match++;
            break;
        default:
            // No action needed for non-matching cases
            break;
        }
    }

    printf("\n");
    // Display a message if no matching records are found
    if (match == 0) {
        printf("*** No records found ***\n\n");
    }
}

    // Get the next highest patient number
    // (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {
    int maxNumber = patient[0].patientNumber; 
    int nextNumber;  // Variable to store the next available patient number

    // Loop through the patient array to find the maximum patient number
    int i;
    for (i = 0; i < max; i++) {
        if (maxNumber < patient[i].patientNumber) {
            maxNumber = patient[i].patientNumber;  // Update maxNum if a higher patient number is found       
        }
    }
    nextNumber = maxNumber + 1;  // Calculate the next available patient number by adding 1 to the maximum patient number    
    return nextNumber;  // Return the calculated next available patient number
}
// Find the patient array index by patient number (returns -1 if not found)
     // (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, 
    const struct Patient patient[], int max) {
    int index = -1;  // Initialize index to -1 (not found)

    // Iterate through the patient array using a while loop
    int i = 0; 
    while (i < max && index == -1) {
        // Check if the patient number in the current array element matches the provided patient number
        if (patient[i].patientNumber == patientNumber) {
            index = i;  // Update the index if the patient number is found
        }

        i++;  // Move to the next element in the array
    }

    return index;  // Return the index of the matching patient (or -1 if not found)
}
    //////////////////////////////////////// USER INPUT FUNCTIONS//////////////////////////////////////
    // // Get user input for a new patient record// 
    // (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {
    int i;  // Variable for iteration through the name array

    // Display input prompt and current patient number
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");

    int flag = 1;  // Flag to control the input loop
    // Loop to input the patient's name, stopping at a newline character or reaching the maximum name length
    for (i = 0; i < NAME_LEN - 1 && flag; i++) { 
        char c = getchar();

        // Check if the entered character is a newline character
        if (c == '\n') {
            flag = 0;  // Set the flag to stop the loop
        }
        else {
            patient->name[i] = c;  // Store the character in the patient's name array
        }
    }

    patient->name[i] = '\0';  // Null-terminate the patient's name array

    printf("\n");
    inputPhoneData(&patient->phone);  // Call the inputPhoneData function to input phone data for the patient
}
    // Get user input for phone contact information
    // (ToDo: PUT THE FUNCTION DEFINITION BELOW)
    // Function to input phone-related data for a patient
void inputPhoneData(struct Phone* phone) {
    int selection;  
    int i; 

    // Display phone information prompt
    printf("Phone Information\n");
    printf("-----------------\n");

    // Display contact type options for the user
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");

    // Read user's choice for contact type
    scanf("%d", &selection);  
    printf("\n");

    // Switch statement based on the user's choice
    switch (selection) {  
    case 1:
        // Set contact type to "CELL" and prompt for the cell phone number
        strcpy(phone->description, "CELL");
        printf("Contact: %s\n", phone->description);
        clearInputBuffer();
        printf("Number : ");
        for (i = 0; i < PHONE_LEN; i++) {
            scanf(" %c", &phone->number[i]);
        }
        printf("\n");
        break;
    case 2:
        // Set contact type to "HOME" and prompt for the home phone number
        strcpy(phone->description, "HOME");
        printf("Contact: %s\n", phone->description);
        clearInputBuffer();
        printf("Number : ");
        for (i = 0; i < PHONE_LEN; i++) {
            scanf(" %c", &phone->number[i]);
        }
        printf("\n");
        break; 
    case 3:
        // Set contact type to "WORK" and prompt for the work phone number
        strcpy(phone->description, "WORK");
        printf("Contact: %s", phone->description);
        printf("\n");
        clearInputBuffer();
        printf("Number : ");
        for (i = 0; i < PHONE_LEN; i++) {
            scanf(" %c", &phone->number[i]);
        }
        printf("\n");
        break;
    case 4:
        // Set contact type to "TBD" and clear the phone number
        strcpy(phone->description, "TBD");
        *phone->number = 0;
        break;
    }
}