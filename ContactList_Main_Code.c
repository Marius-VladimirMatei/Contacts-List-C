#include <stdio.h>
#include <string.h>

void main() {
    char name[2][50];       // Array for  names (2 items, max length 50)
    char phone[2][15];   // Array for telephone numbers (2 items, max length 15)
    int itemCount = 0;

    // Loop for input items and quantities until the array is full
    while (1) {
        if (itemCount >= 2) { // Check if the list is full
            printf_s("Your list is full.\n");
            break;
        }

        printf_s("Enter the name (or press Enter to finish): ");
        fgets(name[itemCount], 50, stdin);

        // Remove newline character added by fgets
        name[itemCount][strcspn(name[itemCount], "\n")] = 0;

        // Check if input is empty
        if (strlen(name[itemCount]) == 0) {
            printf_s("Please enter an item.\n");
            continue; // Ask for input again
        }

        printf_s("Enter telephone number for %s: ", name[itemCount]);
        fgets(phone[itemCount], 15, stdin);

        // Remove newline character added by fgets
        phone[itemCount][strcspn(phone[itemCount], "\n")] = 0;

        itemCount++;
    }

    // Outputs the list
    printf_s("\nYour list contains:\n");
    for (int i = 0; i < itemCount; i++) {
        printf_s("%d. %s - telephone number: %s\n", i + 1, name[i], phone[i]);
    }

}
