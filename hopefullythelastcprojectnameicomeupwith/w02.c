////
////  w02.c
////  hopefullythelastcprojectnameicomeupwith
////
////  Created by User on 5/6/24.
////
//
//
//
//
//#include <stdio.h>
//
//
//
//
//// Function to find the minimum of two integers
//int minimum(int a, int b) {
//    if (a < b) {
//        return a;
//    } else {
//        return b;
//    }
//}
//
//
//int main(void){
//    
//// Part 1
//    int choice = -1;
//    
//    // My humor?
//    printf("It's date night!\n \
//           Walmart carries roses, autumnally-scented candles, ferrero rocher truffles, giant stuffed pandas, and a heated onesie blanket with detachable power cord.");
//    
//    while (choice != 0) {
//        // Display menu
//        printf("\nMenu:\n");
//        printf("1. Candles - $10\n");
//        printf("2. Truffles - $20\n");
//        printf("3. Roses - $15\n");
//        printf("4. Panda - $25\n");
//        printf("5. Blankie - $30\n");
//        printf("Enter the number of the item you want to purchase (1-5), or 0 to exit: ");
//
//        scanf("%d", &choice);
//
//        // Baby's first case statement!
//        // How'd I do?
//        switch (choice) {
//            case 0:
//                printf("Exiting...\n");
//            case 1:
//                printf("You selected Candles. Price: $10\n");
//                break;
//            case 2:
//                printf("You selected Truffles. Price: $20\n");
//                break;
//            case 3:
//                printf("You selected Roses. Price: $15\n");
//                break;
//            case 4:
//                printf("You selected a Panda. Price: $25\n");
//                break;
//            case 5:
//                printf("You selected a Blankie. Price: $30\n");
//                break;
//            default:
//                printf("Invalid choice. Please select a number between 1 and 5.\n");
//                break;
//        }
//    }
//    
//
//// Part 2
//// Loop to print numbers from 1 to 10
//    printf("Numbers between 1 and 10:\n");
//    for (int i = 1; i <= 10; i++) {
//        printf("%d ", i);
//    }
//    printf("\n");
//    
//// Part 3
//// Loop to print numbers from 10 to 1
//    printf("Numbers between 10 and 1:\n");
//    for (int i = 10; i >= 1; i--) {
//        printf("%d ", i);
//    }
//    printf("\n");
//    
//// Part 4
//    float numbers[10];
//    float sum = 0;
//    float min, max;
//
//    // Input loop
//    printf("Enter 10 floating point numbers:\n");
//    for (int i = 0; i < 10; i++) {
//        printf("Enter value %d: ", i + 1);
//        scanf("%f", &numbers[i]);
//        sum += numbers[i];
//    }
//
//    // Calculate min and max
//    min = max = numbers[0];
//    for (int i = 1; i < 10; i++) {
//        if (numbers[i] < min) {
//            min = numbers[i];
//        }
//        if (numbers[i] > max) {
//            max = numbers[i];
//        }
//    }
//
//    // Calculate average
//    float average = sum / 10;
//
//    // Output results
//    printf("\nMinimum value: %.2f\n", min);
//    printf("Maximum value: %.2f\n", max);
//    printf("Average value: %.2f\n", average);
//    
//// Part 5
//    int num1, num2;
//
//    // Input from the user
//    printf("Enter two integers: ");
//    scanf("%d %d", &num1, &num2);
//
//    // Find the minimum using the minimum function
//    int minNum = minimum(num1, num2);
//
//    // Output the result
//    printf("The minimum of %d and %d is %d\n", num1, num2, minNum);
//
//    
//    return 0;
//}
