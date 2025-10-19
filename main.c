#include <stdio.h>
#include "mylib.h"
#include "arraylib.h"

int main(void) {
    int choice, num;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Check Armstrong Number\n");
        printf("2. Check Adams Number\n");
        printf("3. Check Prime Palindrome Number\n");
        printf("4. Test array helper functions (sample)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 5) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        if (choice >=1 && choice <=3) {
            printf("Enter a number: ");
            scanf("%d", &num);
        }

        switch (choice) {
            case 1:
                if (isArmstrong(num))
                    printf("%d is an Armstrong number.\n", num);
                else
                    printf("%d is NOT an Armstrong number.\n", num);
                break;
            case 2:
                if (isAdams(num))
                    printf("%d is an Adams number.\n", num);
                else
                    printf("%d is NOT an Adams number.\n", num);
                break;
            case 3:
                if (isPrimePalindrome(num))
                    printf("%d is a Prime Palindrome number.\n", num);
                else
                    printf("%d is NOT a Prime Palindrome number.\n", num);
                break;
            case 4: {
                int a[] = {3, 1, 4, 1, 5};
                int n = sizeof(a)/sizeof(a[0]);
                printf("Original array: ");
                displayArray(a, n);

                printf("Max at index %d\n", findMaxIndex(a, n));
                printf("Min at index %d\n", findMinIndex(a, n));
                printf("Average = %.2f\n", findAverage(a, n));

                reverseArray(a, n);
                printf("Reversed: ");
                displayArray(a, n);

                sortArray(a, n);
                printf("Sorted: ");
                displayArray(a, n);

                int val = 4;
                int idx = linearSearch(a, n, val);
                if (idx >= 0) printf("Value %d found at index %d\n", val, idx);
                else printf("Value %d not found\n", val);
                break;
            }
            default:
                printf("Invalid choice! Please select between 1–5.\n");
        }

    } while (choice != 5);

    return 0;
}
