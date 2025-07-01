// ContactServices.c
#include <stdio.h>
#include <string.h>
#include "ContactServices.h"

Contact Contacts[MAX_CONTACTS];
int totalContacts = 0;
int nextId = 1;

void registerContact() {
    if (totalContacts >= MAX_CONTACTS) {
        printf("Agenda cheia!\n");
        return;
    }

    Contact novo;
    novo.id = nextId++;

    getchar();
    printf("name: ");
    fgets(novo.name, sizeof(novo.name), stdin);
    novo.name[strcspn(novo.name, "\n")] = '\0';

    printf("phone: ");
    fgets(novo.phone, sizeof(novo.phone), stdin);
    novo.phone[strcspn(novo.phone, "\n")] = '\0';

    printf("isPersonal (pessoal/trabalho): ");
    fgets(novo.isPersonal, sizeof(novo.isPersonal), stdin);
    novo.isPersonal[strcspn(novo.isPersonal, "\n")] = '\0';

    Contacts[totalContacts++] = novo;
    printf("Contact registrado! ID: %d\n", novo.id);
}

void showAllContacts() {
    if (totalContacts == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    for (int i = 0; i < totalContacts; i++) {
        printf("\nID: %d\nname: %s\nphone: %s\nisPersonal: %s\n",
            Contacts[i].id, Contacts[i].name, Contacts[i].phone, Contacts[i].isPersonal);
    }
}

void searchContact() {
    int id;
    printf("ID do Contact: ");
    scanf("%d", &id);

    for (int i = 0; i < totalContacts; i++) {
        if (Contacts[i].id == id) {
            printf("\nID: %d\nname: %s\nphone: %s\nisPersonal: %s\n",
                Contacts[i].id, Contacts[i].name, Contacts[i].phone, Contacts[i].isPersonal);
            return;
        }
    }

    printf("Contact não encontrado.\n");
}

void editContact() {
    int id;
    printf("ID do Contact a editar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalContacts; i++) {
        if (Contacts[i].id == id) {
            getchar();
            printf("Novo name: ");
            fgets(Contacts[i].name, sizeof(Contacts[i].name), stdin);
            Contacts[i].name[strcspn(Contacts[i].name, "\n")] = '\0';

            printf("Novo phone: ");
            fgets(Contacts[i].phone, sizeof(Contacts[i].phone), stdin);
            Contacts[i].phone[strcspn(Contacts[i].phone, "\n")] = '\0';

            printf("Novo isPersonal: ");
            fgets(Contacts[i].isPersonal, sizeof(Contacts[i].isPersonal), stdin);
            Contacts[i].isPersonal[strcspn(Contacts[i].isPersonal, "\n")] = '\0';

            printf("Contact atualizado!\n");
            return;
        }
    }

    printf("Contact não encontrado.\n");
}

void deleteContact() {
    int id;
    printf("ID do Contact a excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < totalContacts; i++) {
        if (Contacts[i].id == id) {
            for (int j = i; j < totalContacts - 1; j++) {
                Contacts[j] = Contacts[j + 1];
            }
            totalContacts--;
            printf("Contact excluído!\n");
            return;
        }
    }

    printf("Contact não encontrado.\n");
}
