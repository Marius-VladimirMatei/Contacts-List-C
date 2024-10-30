#include <stdio.h>
#include <string.h>

// constants to define the array size
#define max_items 2
#define max_phone_length 50

typedef struct Contact {
    char name[max_phone_length];
    char phone[max_phone_length];
} Contact;


void main() {
    Contact inventory[max_items];
    int itemCount = 0;

    // Loop for input items and quantities until the array is full
    while (1) {
        // Check if the list is full
        if (itemCount >= max_items) {
            printf_s("Your contact list is full.\n");
            break;
        }

        printf_s("Enter the name (or press Enter to finish): ");
        fgets(inventory[itemCount].name, max_phone_length, stdin);

        // Remove newline character added by fgets
        inventory[itemCount].name[strcspn(inventory[itemCount].name, "\n")] = 0;

        // Check if input is empty
        if (strlen(inventory[itemCount].name) == 0) {
            printf_s("Please enter a name.\n");
            continue; // Ask for input again
        }

        printf_s("Enter telephone number for %s: ", inventory[itemCount].name);
        fgets(inventory[itemCount].phone, max_phone_length, stdin);

        // Remove newline character added by fgets
        inventory[itemCount].phone[strcspn(inventory[itemCount].phone, "\n")] = 0;

        itemCount++;
    }

    // Outputs the list
    printf_s("\nYour list contains:\n");
    for (int i = 0; i < itemCount; i++) {
        printf_s("%d. %s - telephone number: %s\n", i + 1, inventory[i].name, inventory[i].phone);
    }

}
