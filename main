#include <stdio.h>
#include "ContactServices.h"

typedef struct {
    int id;
    char name[100];
    char phone[15];
    int isPersonal;
} Contact;

int main() {
    int menuOption = 0;

    do {
        printf("\n=== CONTACT BOOK ===\n");
        printf("[1] - Show all contacts.\n");
        printf("[2] - Search a contact.\n");
        printf("[3] - Register new contact.\n");
        printf("[4] - Edit a contact.\n");
        printf("[5] - Delete a contact.\n");
        printf("[0] - Log out.\n\n");
        printf("Select one option: ");
        scanf("%d", &menuOption);

        switch (menuOption) {
        case 1: showAllContacts(); break;
        case 2: searchContact(); break;
        case 3: registerContact(); break;
        case 4: editContact(); break;
        case 5: deleteContact(); break;
        case 0: printf("Loggin out...\n"); break;
        default: printf("Invalid Option.\n");
        }

    } while (menuOption != 0);
};
