//
//  w03_2.c
//  hopefullythelastcprojectnameicomeupwith
//
//  Created by User on 5/8/24.
//

#include "w03_2.h"

struct firstStruct{
    int accNum;
    float balance;
    char name[20];
};
// Allows the user to create an account
void inputAccountInfo(struct firstStruct *stru){
    printf("Enter account number: ");
    scanf("%d", &(stru->accNum));

    printf("Enter name: ");
    scanf("%s", stru->name);

    printf("Enter balance: ");
    scanf("%f", &(stru->balance));
}
// Displays account info
void displayAccountInfo(const struct firstStruct *stru) {
    printf("\nAccount number: %d\n", stru->accNum);
    printf("Name: %s\n", stru->name);
    printf("Balance: %.2f\n", stru->balance);
}

int main(void){
    struct firstStruct myAcc;
    inputAccountInfo(&myAcc);
    displayAccountInfo(&myAcc);
    return 0;
}
