//#pragma once
//#include "main.c"
// ContactServices.h
#ifndef CONTACT_SERVICE_H
#define CONTACT_SERVICE_H

#define MAX_CONTACTS 100

extern Contact contacts[MAX_CONTACTS];
extern int totalContacts;
extern int nextId;

void showAllContacts();
void searchContact();
void registerContact();
void editContact();
void deleteContact();

#endif
