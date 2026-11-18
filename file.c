
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

// Save reservation records
void saveReservations(Reservation *head) {

    FILE *fp = fopen("reservations.txt", "w");

    if (fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }

    Reservation *temp = head;

    while (temp != NULL) {

        fprintf(fp, "%s\n", temp->name);
        fprintf(fp, "%d\n", temp->trainNumber);
        fprintf(fp, "%d\n", temp->seatNumber);
        fprintf(fp, "%d\n", temp->age);
        fprintf(fp, "%s\n", temp->gender);
        fprintf(fp, "%s\n", temp->source);
        fprintf(fp, "%s\n", temp->destination);

        temp = temp->next;
    }

    fclose(fp);

    printf("Records saved successfully!\n");
}

// Read one line from file
int readFileLine(FILE *fp, char str[], int size) {

    if (fgets(str, size, fp) == NULL) {
        return 0;
    }

    str[strcspn(str, "\r\n")] = '\0';

    return 1;
}

// Load reservation records
void loadReservations(Reservation **head) {

    FILE *fp = fopen("reservations.txt", "r");

    if (fp == NULL) {
        return;
    }

    while (1) {

        Reservation *newNode = malloc(sizeof(Reservation));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            break;
        }

        char train[20], seat[20], age[20];

        if (!readFileLine(fp, newNode->name, 50) ||
            !readFileLine(fp, train, 20) ||
            !readFileLine(fp, seat, 20) ||
            !readFileLine(fp, age, 20) ||
            !readFileLine(fp, newNode->gender, 10) ||
            !readFileLine(fp, newNode->source, 50) ||
            !readFileLine(fp, newNode->destination, 50)) {

            free(newNode);
            break;
        }

        newNode->trainNumber = atoi(train);
        newNode->seatNumber = atoi(seat);
        newNode->age = atoi(age);

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
    }

    fclose(fp);
}
