
#include <stdio.h>
#include "reservation.h"
#include "file.h"

int main() {

    Reservation *head = NULL;

    int choice;

    // Load previously saved records
    loadReservations(&head);

    printf("================================\n");
    printf("   RAILWAY RESERVATION SYSTEM\n");
    printf("================================\n");

    while (1) {

        printf("\n========== MAIN MENU ==========\n");

        printf("1. Create Reservation\n");
        printf("2. Display Records\n");
        printf("3. Insert Record\n");
        printf("4. Modify Record\n");
        printf("5. Delete Record\n");
        printf("6. Search Record\n");
        printf("7. Sort Records\n");
        printf("8. Save Records\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        // Clear input buffer
        while (getchar() != '\n');

        switch (choice) {

            case 1:
                createReservation(&head);
                saveReservations(head);
                break;

            case 2:
                displayReservations(head);
                break;

            case 3:
                insertReservation(&head);
                saveReservations(head);
                break;

            case 4:
                modifyReservation(head);
                saveReservations(head);
                break;

            case 5:
                deleteReservation(&head);
                saveReservations(head);
                break;

            case 6:
                searchReservation(head);
                break;

            case 7:
                sortReservations(head);
                saveReservations(head);
                break;

            case 8:
                saveReservations(head);
                break;

            case 9:
                saveReservations(head);
                freeReservations(head);

                printf("\nThank you for using Railway Reservation System!\n");

                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
