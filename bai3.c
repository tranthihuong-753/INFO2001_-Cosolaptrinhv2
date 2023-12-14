#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

void addContact(struct Contact contact, FILE *file) {
    fwrite(&contact, sizeof(struct Contact), 1, file);
    printf("Contact added successfully.\n");
}

void removeContact(char name[50], FILE *file) {
    FILE *tempFile = fopen("temp.dat", "wb");
    struct Contact contact;
    int found = 0;

    while (fread(&contact, sizeof(struct Contact), 1, file)) {
        if (strcmp(contact.name, name) != 0) {
            fwrite(&contact, sizeof(struct Contact), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");
        printf("Contact removed successfully.\n");
    } else {
        remove("temp.dat");
        printf("Contact not found.\n");
    }
}

void updateContact(char name[50], struct Contact new_data, FILE *file) {
    FILE *tempFile = fopen("temp.dat", "wb");
    struct Contact contact;
    int found = 0;

    while (fread(&contact, sizeof(struct Contact), 1, file)) {
        if (strcmp(contact.name, name) == 0) {
            fwrite(&new_data, sizeof(struct Contact), 1, tempFile);
            found = 1;
        } else {
            fwrite(&contact, sizeof(struct Contact), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");
        printf("Contact updated successfully.\n");
    } else {
        remove("temp.dat");
        printf("Contact not found.\n");
    }
}

void searchContact(char name[50], FILE *file) {
    struct Contact contact;
    int found = 0;

    while (fread(&contact, sizeof(struct Contact), 1, file)) {
        if (strcmp(contact.name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contact.name);
            printf("Phone: %s\n", contact.phone);
            printf("Email: %s\n", contact.email);
            printf("---------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayContacts(FILE *file) {
    struct Contact contact;

    while (fread(&contact, sizeof(struct Contact), 1, file)) {
        printf("Name: %s\n", contact.name);
        printf("Phone: %s\n", contact.phone);
        printf("Email: %s\n", contact.email);
        printf("---------------------\n");
    }
}

int main() {
    FILE *file = fopen("contacts.dat", "ab+");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int choice;
    struct Contact contact;

    do {
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Update contact\n");
        printf("4. Search contact\n");
        printf("5. Display contacts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]", contact.name);
                printf("Enter phone: ");
                scanf(" %[^\n]", contact.phone);
                printf("Enter email: ");
                scanf(" %[^\n]", contact.email);
                addContact(contact, file);
                break;
            case 2:
                printf("Enter name: ");
                scanf(" %[^\n]", contact.name);
                removeContact(contact.name, file);
                break;
            case 3:
                printf("Enter name: ");
                scanf(" %[^\n]", contact.name);
                printf("Enter new phone: ");
                scanf(" %[^\n]", contact.phone);
                printf("Enter new email: ");
                scanf(" %[^\n]", contact.email);
               updateContact(contact.name, contact, file);
                break;
            case 4:
                printf("Enter name: ");
                scanf(" %[^\n]", contact.name);
                searchContact(contact.name, file);
                break;
            case 5:
                displayContacts(file);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    fclose(file);

    return 0;
}
