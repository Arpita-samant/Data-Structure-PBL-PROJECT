
#ifndef RESERVATION_H
#define RESERVATION_H

struct Reservation {
    char name[50];
    int trainNumber;
    int seatNumber;
    int age;
    char gender[10];
    char source[50];
    char destination[50];

    struct Reservation *next;
};

typedef struct Reservation Reservation;

// Function declarations

void createReservation(Reservation **head);
void insertReservation(Reservation **head);
void displayReservations(Reservation *head);
void modifyReservation(Reservation *head);
void deleteReservation(Reservation **head);
void searchReservation(Reservation *head);
void sortReservations(Reservation *head);
void freeReservations(Reservation *head);

#endif
