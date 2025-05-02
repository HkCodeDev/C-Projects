#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

int convertToMinutes(struct Appointment appoint) { 
    return (appoint.date.year * MINUTES_IN_YEAR) +
           (appoint.date.month * MINUTES_IN_MONTH) +
           (appoint.date.day * MINUTES_IN_DAY) +
           (appoint.time.hour * MINUTES_IN_HOUR) +
           appoint.time.min;
}
void sort(struct Appointment appoints[], int max) {
    struct Appointment swap; 
    int i;
    int j;
    // Convert dates and times to total minutes
    for (i = 0; i < max; i++) {
        appoints[i].time.min = convertToMinutes(appoints[i]);
    }

    // Bubble sort based on total minutes
    for (i = max - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (appoints[j].time.min > appoints[j + 1].time.min) {
                swap = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = swap; 
            }
        }
    }

    // Convert total minutes back to individual date and time components
    for (i = 0; i < max; i++) {
        appoints[i].time.min -= (appoints[i].date.year * MINUTES_IN_YEAR) +
            (appoints[i].date.month * MINUTES_IN_MONTH) +
            (appoints[i].date.day * MINUTES_IN_DAY) +
            (appoints[i].time.hour * MINUTES_IN_HOUR);
    }
}

void inputPhoneNumber(char* phoneNumber) { 
    int size = 0;
    int i;
    // Flag to indicate whether the input is invalid initially
    int invalidInput = 1;

    // Ensure the array is large enough to accommodate the maximum length
    char tempArray[MEMORY];

    while (invalidInput) {
        // Use tempArray for input to avoid overwriting string in case of invalid input
        printf("Number : "); 
        scanf(" %[^\n]%*c", tempArray);
         size = 0;
        while (tempArray[size] != '\0') {
            size++;
        }

        if (size != 10) {
            // Set the flag to indicate invalid input
            invalidInput = 1;
            printf("Invalid 10-digit number! ");
        }
        else {
            // Reset the flag as the input is valid
            invalidInput = 0;
        }
    }
    printf("\n");
  
    // Copy characters to the output parameter
    for (i = 0; i <= size; i++) {
        phoneNumber[i] = tempArray[i];
    }
    // Null-terminate the string
    phoneNumber[size] = '\0';
}
void handlePhoneOption(struct Phone* phone, const char* description) {
    strncpy(phone->description, description, PHONE_DESC_LEN + 1);

    if (strcmp(description, "TBD") != 0) {
        printf("Contact: %s\n", phone->description);
        inputPhoneNumber(phone->number);
    }
    else {
        *phone->number = '\0';
    }
}

 
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
void displayPatientData(const struct Patient* patient, int fmt) {
    if (fmt == FMT_FORM) {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else {
        printf("%05d %-15s ", patient->patientNumber, patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int i, eligible_record = 0;
    if (fmt == FMT_TABLE) {
        displayPatientTableHeader();
    }
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            eligible_record = 1;
        }
    }
    if (!eligible_record) {
        printf("*** No records found ***\n\n");
    }
    printf("\n");
}
// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
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


// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
    int patientNum;
    int index = -1;
    int i;
    // Initialize index to -1 to indicate no empty space found

    // Find the first empty space in the patient array
    for (i = 0; i < max && index == -1; i++) {
        if (patient[i].patientNumber == 0) {
            index = i; // Found an empty slot
        }
    }

    // Check if an empty space was found
    if (index == -1) {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else {
        // Assign a new patient number and input patient details
        patientNum = nextPatientNumber(patient, max); 
        patient[index].patientNumber = patientNum; 
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
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
// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
    int patientNum;
    int index;
    char selection;
    char character;  
    int flag = 1; 
    printf("Enter the patient number: ");
    scanf("%d", &patientNum); 
    printf("\n");
    // Checking if patient number exists    
    if (findPatientIndexByPatientNum(patientNum, patient, max) != -1) {
        index = findPatientIndexByPatientNum(patientNum, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
  
        do {
            scanf(" %c%c", &selection, &character);
            if ((selection == 'n') && (character == '\n')) {
                printf("Operation aborted.\n\n");
                flag = 0;
                clearInputBuffer();
            }
            else if ((selection == 'y') && (character == '\n')) { 
                patient[index].patientNumber = 0;
                printf("Patient record has been removed!\n\n");
                flag = 0;
            }
            else {
                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while (flag);
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
} 
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:

void viewAllAppointments(struct ClinicData* data) {
    int i;
    int j;
    // Sorting the data in the array    
    sort(data->appointments, data->maxAppointments);
    // Displaying the patients
    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }    printf("\n");
}
// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {
    int i;
    int j; 
    struct Date date;
    int final = 31;

    // Input date information
    printf("Year        : ");
    date.year = inputIntPositive();
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);
    printf("Day (1-%d)  : ", (date.month == 2 && (date.year % 4 == 0) ? 29 : (date.month == 2 ? 28 : (date.month == 4 || date.month == 9 || date.month == 11 ? 30 : 31))));
    date.day = inputIntRange(1, final);
    printf("\n");

    // Sort appointments
    sort(data->appointments, data->maxAppointments);

    // Display schedule table header
    displayScheduleTableHeader(&date, 0);

    // Display appointments for the specified date
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber &&
                data->appointments[i].patientNumber == data->patients[j].patientNumber &&
                data->appointments[i].date.year == date.year &&
                data->appointments[i].date.month == date.month &&
                data->appointments[i].date.day == date.day) {
                displayScheduleData(&data->patients[j], &data->appointments[i], 0);
            }
        }
    }

    printf("\n");
}
// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments,
    int maxAppointments, struct Patient* patients, int maxPatients) {
    struct Date date;
    struct Time time;

    // Declaring variables    
    int patientNumber;
    int indexP, indexA;
    int flag = 1;
    int final = 31;

    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    indexP = findPatientIndexByPatientNum(patientNumber, patients, maxPatients);

    if (indexP >= 0) {
        while (flag) {
            // Get appointment date
            printf("Year        : ");
            date.year = inputIntPositive();

            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);

            switch (date.month) {
            case 4:
            case 6:
            case 9:
            case 11:
                final = 30;
                break;
            case 2:
                final = (date.year % 4 == 0) ? 29 : 28;
                break;
            default:
                final = 31;
                break;
            }

            printf("Day (1-%d)   : ", final);
            date.day = inputIntRange(1, final);

            // Get appointment time
            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);
            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            // Check if the timeslot is available
            int i = 0;
            int timeSlotTaken = 0;

            while (i < maxAppointments && !timeSlotTaken) {
                // Checking if time slot is available        
                if (date.year == appointments[i].date.year &&
                    date.month == appointments[i].date.month &&
                    date.day == appointments[i].date.day &&
                    time.hour == appointments[i].time.hour &&
                    time.min == appointments[i].time.min)
                {
                    timeSlotTaken = 1;
                }
                i++;
            }

            if (timeSlotTaken) {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else {
                // Validate time range and minute intervals
                while ((time.hour < 10 || time.hour > 14) ||
                    (time.hour == 14 && time.min > 0) ||
                    (time.min % 30 != 0)) {
                    printf("ERROR: Time must be between %02d:00 "
                        "and %02d:00 in %02d minute intervals.\n\n",
                        10, 14, 30);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);
                }

                // Find the next available slot
                indexA = -1;
                for (i = 0; i < maxAppointments; i++) {
                    if (appointments[i].patientNumber < 1) {
                        indexA = i;
                        break;
                    }
                }

                if (indexA != -1) {
                    // Schedule the appointment
                    appointments[indexA].date = date;
                    appointments[indexA].time = time;
                    appointments[indexA].patientNumber = patientNumber;

                    printf("\n*** Appointment scheduled! ***\n\n");
                    flag = 0;  // Exit the while loop
                }
                else {
                    printf("\nERROR: No available slot found!\n\n");
                    flag = 0;  // Exit the while loop
                }
            }
        }
    }
    else {
        printf("\nERROR: Patient record not found!\n\n");
    }
} 

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatients) {
    struct Date date;
    int patientNumber;
    int index;
    int final = 0;
    int indexA = -1;
    int i;// Initialize indexA with a flag indicating no appointment found

    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, patients, maxPatients);

    if (index >= 0) {
        printf("Year        : ");
        date.year = inputIntPositive();
        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);

        int monthFlag = 0;  // Flag for valid month
        switch (date.month) {
        case 4:
        case 6:
        case 9:
        case 11:
            final = 30;
            monthFlag = 1;
            break;
        case 2:
            monthFlag = 1;
            final = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0) ? 29 : 28;
            break;
        default:
            monthFlag = 1;
            final = 31;
            break;
        }

        if (monthFlag) {
            printf("Day (1-%d)  : ", final);
            date.day = inputIntRange(1, final);

            // Check if the appointment exists
            int appointmentFlag = 0;  // Flag for appointment found
            for (i = 0; i < maxAppointments && appointmentFlag == 0; i++) {
                if (appointments[i].patientNumber == patientNumber &&
                    appointments[i].date.day == date.day &&
                    appointments[i].date.month == date.month &&
                    appointments[i].date.year == date.year) {
                    indexA = i;
                    appointmentFlag = 1;
                }
            }

            if (appointmentFlag) {
                printf("\n");
                displayPatientData(&patients[index], FMT_FORM);
                printf("Are you sure you want to remove this appointment (y,n): ");

                switch (inputCharOption("yn")) {
                case 'y':
                    appointments[indexA].patientNumber = 0;
                    printf("\nAppointment record has been removed!\n\n");
                    break;
                default:
                    printf("Operation canceled. No appointment removed.\n\n");
                    break;
                }
            }
            else {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
    }
} 
 
//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}
// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone) {
    int selection;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, PHONE_DESC_LEN + 1);
    putchar('\n');

    switch (selection) {
    case 1:
        handlePhoneOption(phone, "CELL");
        break;
    case 2:
        handlePhoneOption(phone, "HOME");
        break;
    case 3:
        handlePhoneOption(phone, "WORK");
        break;
    case 4:
        handlePhoneOption(phone, "TBD");
        break;
    }
}
//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {
    int i = 0;
    int count = 0;
    FILE* fp = fopen(datafile, "r");
    if (fp != NULL) {
        while (i < max && !feof(fp) && fscanf(fp, 
            "%d|%[^|]|%[^|]|%[^'\n']", &(patients[i].patientNumber), 
            patients[i].name, patients[i].phone.description, 
            patients[i].phone.number)) {
            count++;
            i++;
        }
        fclose(fp);
        fp = NULL;
    }
    return count;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {   
    int i;
    int count = 0;
    FILE* fp;
    fp = fopen(datafile, "r");   
    if (fp != NULL) {       
        for (i = 0; i < max && !feof(fp); i++) {
            fscanf(fp, "%d,%d,%d,%d,%d,%d",
                &appoints[i].patientNumber, 
                &appoints[i].date.year, &appoints[i].date.month, 
                &appoints[i].date.day, &appoints[i].time.hour, 
                &appoints[i].time.min);            
            if (!feof(fp)) {
                count++;
            }
        }       
        fclose(fp);
    }
    else {
        printf("ERROR: File could not be read\n");
    }   
    return count;
}
