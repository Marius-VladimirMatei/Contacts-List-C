#include <stdio.h>
#include <string.h>

// Variables to define the array size
#define max_items 2
#define max_phone_length 15

// Define the structure for contacts
typedef struct {
    char name[max_phone_length];
    char phone[max_phone_length];
} Contact;

// Function prototypes
void addContact(Contact inventory[], int* itemCount);
void showContacts(Contact inventory[], int itemCount);
void searchContacts(Contact inventory[], int itemCount);

void main() {
    Contact inventory[max_items];
    int itemCount = 0;
    int choice;

    while (1) {
        // Display the menu
        printf("1. Add the contact name\n");
        printf("2. Show all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf_s("%d", &choice);

        // Clear input buffer
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            addContact(inventory, &itemCount);
            break;
        case 2:
            showContacts(inventory, itemCount);
            break;
        case 3:
            searchContacts(inventory, itemCount);
            break;
        case 4:
            printf_s("Exiting...\n");
            return 0;
        default:
            printf_s("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a contact to the inventory
void addContact(Contact inventory[], int* itemCount) {
    // Check if the inventory is full
    if (*itemCount >= max_items) {
        printf_s("Your list is full.\n");
        printf_s("__________________________________\n");
        return;
    }

    // Prompt for contact name
    printf_s("Enter your contact name: ");
    fgets(inventory[*itemCount].name, max_phone_length, stdin);

    // Remove newline
    inventory[*itemCount].name[strcspn(inventory[*itemCount].name, "\n")] = 0; 

    // Check if input is empty
    if (strlen(inventory[*itemCount].name) == 0) {
        printf_s("Please enter a contact name.\n");
        printf_s("__________________________________\n");
        return; // Do not increment itemCount
    }

    // Prompt for phone number
    printf_s("Enter telephone number for %s: ", inventory[*itemCount].name);
    fgets(inventory[*itemCount].phone, max_phone_length, stdin);

    // Remove newline
    inventory[*itemCount].phone[strcspn(inventory[*itemCount].phone, "\n")] = 0;

    (*itemCount)++;
}

// Function to show all contacts in the inventory list
void showContacts(Contact inventory[], int itemCount) {
    if (itemCount == 0) {
        printf_s("Your contact list is empty.\n");
        printf_s("__________________________________\n");
        return;
    }

    printf_s("\nYour contact list contains:\n");
    for (int i = 0; i < itemCount; i++) {
        printf_s("%d. %s - phone number: %s\n", i + 1, inventory[i].name, inventory[i].phone);
        printf_s("__________________________________\n");
    }
}

// Function to search for an contact by name
void searchContacts(Contact inventory[], int itemCount) {
    char searchName[max_phone_length];
    printf_s("Enter the name of the item to search for: ");
    printf_s("__________________________________\n");
    fgets(searchName, max_phone_length, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Contact found: %s - phone number: %s\n", inventory[i].name, inventory[i].phone);
            found = 1;
            printf_s("__________________________________\n");
            break;
        }
    }

    if (!found) {
        printf("Contact '%s' not found in inventory.\n", searchName);
        printf_s("__________________________________\n");
    }
}
