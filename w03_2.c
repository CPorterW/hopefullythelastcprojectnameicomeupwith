//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Account {
//    int accNum;
//    float balance;
//    char name[20];
//    struct Account* next;
//};
//
//// Allows the user to create an account
//void inputAccountInfo(struct Account *acc) {
//    printf("Enter account number: ");
//    scanf("%d", &(acc->accNum));
//
//    printf("Enter name: ");
//    scanf("%s", acc->name);
//
//    printf("Enter balance: ");
//    scanf("%f", &(acc->balance));
//}
//
//// Displays account info
//void displayAccountInfo(const struct Account *acc) {
//    printf("\nAccount number: %d\n", acc->accNum);
//    printf("Name: %s\n", acc->name);
//    printf("Balance: %.2f\n", acc->balance);
//}
//
//void displayAllAccounts(const struct Account *head) {
//    const struct Account *current = head;
//    while (current != NULL) {
//        displayAccountInfo(current);
//        current = current->next;
//    }
//}
//
//struct Account* addAccount(struct Account *head) {
//    struct Account *newAcc = (struct Account*)malloc(sizeof(struct Account));
//    if (newAcc == NULL) {
//        printf("Memory allocation failed. Exiting...\n");
//        exit(1);
//    }
//
//    inputAccountInfo(newAcc);
//    newAcc->next = NULL;
//
//    if (head == NULL) {
//        head = newAcc;
//    } else {
//        struct Account *current = head;
//        while (current->next != NULL) {
//            current = current->next;
//        }
//        current->next = newAcc;
//    }
//
//    return head;
//}
//
//void findAccount(const struct Account *head, int accNum) {
//    const struct Account *current = head;
//    while (current != NULL) {
//        if (current->accNum == accNum) {
//            displayAccountInfo(current);
//            return;
//        }
//        current = current->next;
//    }
//    printf("Account not found.\n");
//}
//
//void updateAccount(struct Account *head, int accNum) {
//    struct Account *current = head;
//    while (current != NULL) {
//        if (current->accNum == accNum) {
//            inputAccountInfo(current);
//            printf("Account updated successfully.\n");
//            return;
//        }
//        current = current->next;
//    }
//    printf("Account not found.\n");
//}
//
//int main(void) {
//    struct Account *head = NULL;
//
//    int choice;
//    do {
//        printf("\nMain menu:\n");
//        printf("1. Add account\n");
//        printf("2. Display all accounts\n");
//        printf("3. Find account\n");
//        printf("4. Update account\n");
//        printf("0. Quit program\n");
//        printf("Your choice: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//            case 1: // Add account
//                head = addAccount(head);
//                break;
//            case 2: // Display all accounts
//                displayAllAccounts(head);
//                break;
//            case 3: // Find account
//                printf("Enter the account number to find: ");
//                int accNum;
//                scanf("%d", &accNum);
//                findAccount(head, accNum);
//                break;
//            case 4: // Update account
//                printf("Enter the account number to update: ");
//                int updateAccNum;
//                scanf("%d", &updateAccNum);
//                updateAccount(head, updateAccNum);
//                break;
//            case 0: // Quit program
//                printf("Exiting program.\n");
//                break;
//            default:
//                printf("Invalid choice. Please enter a valid option.\n");
//        }
//    } while (choice != 0);
//
//    // Free allocated memory
//    struct Account *temp;
//    while (head != NULL) {
//        temp = head;
//        head = head->next;
//        free(temp);
//    }
//
//    return 0;
//}
