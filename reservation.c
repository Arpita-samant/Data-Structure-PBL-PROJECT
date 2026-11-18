
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservation.h"

// Function to read text
void readLine(char str[], int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

// Function to read integer
int readInt() {
    char input[50];
    readLine(input, sizeof(input));
    return atoi(input);
}

// Create a new reservation at the end
void createReservation(Reservation **head) {

    Reservation *newNode = malloc(sizeof(Reservation));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    readLine(newNode->name, 50);

    printf("Enter Train Number: ");
    newNode->trainNumber = readInt();

    printf("Enter Seat Number: ");
    newNode->seatNumber = readInt();

    printf("Enter Age: ");
    newNode->age = readInt();

    printf("Enter Gender: ");
    readLine(newNode->gender, 10);

    printf("Enter Source: ");
    readLine(newNode->source, 50);

    printf("Enter Destination: ");
    readLine(newNode->destination, 50);

    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Reservation *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nReservation created successfully!\n");
}

// Insert a new reservation at the beginning
void insertReservation(Reservation **head) {

    Reservation *newNode = malloc(sizeof(Reservation));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    readLine(newNode->name, 50);

    printf("Enter Train Number: ");
    newNode->trainNumber = readInt();

    printf("Enter Seat Number: ");
    newNode->seatNumber = readInt();

    printf("Enter Age: ");
    newNode->age = readInt();

    printf("Enter Gender: ");
    readLine(newNode->gender, 10);

    printf("Enter Source: ");
    readLine(newNode->source, 50);

    printf("Enter Destination: ");
    readLine(newNode->destination, 50);

    newNode->next = *head;
    *head = newNode;

    printf("\nRecord inserted successfully!\n");
}

// Display all reservations
void displayReservations(Reservation *head) {

    Reservation *temp = head;

    if (temp == NULL) {
        printf("\nNo reservation records found!\n");
        return;
    }

    printf("\n===== ALL RESERVATION RECORDS =====\n");

    while (temp != NULL) {

        printf("\nPassenger Name: %s", temp->name);
        printf("\nTrain Number: %d", temp->trainNumber);
        printf("\nSeat Number: %d", temp->seatNumber);
        printf("\nAge: %d", temp->age);
        printf("\nGender: %s", temp->gender);
        printf("\nSource: %s", temp->source);
        printf("\nDestination: %s\n", temp->destination);

        temp = temp->next;
    }
}

// Modify a reservation
void modifyReservation(Reservation *head) {

    char name[50];
    int train;

    printf("Enter Passenger Name: ");
    readLine(name, 50);

    printf("Enter Train Number: ");
    train = readInt();

    Reservation *temp = head;

    while (temp != NULL) {

        if (strcmp(temp->name, name) == 0 &&
            temp->trainNumber == train) {

            printf("Enter New Seat Number: ");
            temp->seatNumber = readInt();

            printf("Enter New Age: ");
            temp->age = readInt();

            printf("Enter New Gender: ");
            readLine(temp->gender, 10);

            printf("Enter New Source: ");
            readLine(temp->source, 50);

            printf("Enter New Destination: ");
            readLine(temp->destination, 50);

            printf("\nRecord updated successfully!\n");
            return;
        }

        temp = temp->next;
    }

    printf("\nReservation not found!\n");
}

// Delete a reservation
void deleteReservation(Reservation **head) {

    char name[50];
    int train;

    printf("Enter Passenger Name: ");
    readLine(name, 50);

    printf("Enter Train Number: ");
    train = readInt();

    Reservation *temp = *head;
    Reservation *previous = NULL;

    while (temp != NULL) {

        if (strcmp(temp->name, name) == 0 &&
            temp->trainNumber == train) {

            if (previous == NULL) {
                *head = temp->next;
            } else {
                previous->next = temp->next;
            }

            free(temp);

            printf("\nRecord deleted successfully!\n");
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    printf("\nReservation not found!\n");
}

// Search reservation by name or train number
void searchReservation(Reservation *head) {

    int choice, train, found = 0;
    char name[50];

    printf("\n1. Search by Passenger Name");
    printf("\n2. Search by Train Number");
    printf("\nEnter Choice: ");

    choice = readInt();

    if (choice == 1) {
        printf("Enter Passenger Name: ");
        readLine(name, 50);
    } 
    else if (choice == 2) {
        printf("Enter Train Number: ");
        train = readInt();
    } 
    else {
        printf("Invalid choice!\n");
        return;
    }

    Reservation *temp = head;

    while (temp != NULL) {

        if ((choice == 1 && strcmp(temp->name, name) == 0) ||
            (choice == 2 && temp->trainNumber == train)) {

            printf("\nPassenger Name: %s", temp->name);
            printf("\nTrain Number: %d", temp->trainNumber);
            printf("\nSeat Number: %d", temp->seatNumber);
            printf("\nAge: %d", temp->age);
            printf("\nGender: %s", temp->gender);
            printf("\nSource: %s", temp->source);
            printf("\nDestination: %s\n", temp->destination);

            found = 1;
        }

        temp = temp->next;
    }

    if (!found) {
        printf("\nRecord not found!\n");
    }
}

// Sort records by name or train number
void sortReservations(Reservation *head) {

    int choice;

    printf("\n1. Sort by Passenger Name");
    printf("\n2. Sort by Train Number");
    printf("\nEnter Choice: ");

    choice = readInt();

    if (choice != 1 && choice != 2) {
        printf("Invalid choice!\n");
        return;
    }

    if (head == NULL) {
        printf("No records to sort!\n");
        return;
    }

    Reservation *i, *j;

    for (i = head; i != NULL; i = i->next) {

        for (j = i->next; j != NULL; j = j->next) {

            int swap = 0;

            if (choice == 1 &&
                strcmp(i->name, j->name) > 0) {
                swap = 1;
            }

            if (choice == 2 &&
                i->trainNumber > j->trainNumber) {
                swap = 1;
            }

            if (swap) {

                Reservation temp;

                strcpy(temp.name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp.name);

                temp.trainNumber = i->trainNumber;
                i->trainNumber = j->trainNumber;
                j->trainNumber = temp.trainNumber;

                temp.seatNumber = i->seatNumber;
                i->seatNumber = j->seatNumber;
                j->seatNumber = temp.seatNumber;

                temp.age = i->age;
                i->age = j->age;
                j->age = temp.age;

                strcpy(temp.gender, i->gender);
                strcpy(i->gender, j->gender);
                strcpy(j->gender, temp.gender);

                strcpy(temp.source, i->source);
                strcpy(i->source, j->source);
                strcpy(j->source, temp.source);

                strcpy(temp.destination, i->destination);
                strcpy(i->destination, j->destination);
                strcpy(j->destination, temp.destination);
            }
        }
    }

    printf("\nRecords sorted successfully!\n");
}

// Free linked list memory
void freeReservations(Reservation *head) {

    Reservation *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
