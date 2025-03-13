#include<stdio.h>

int main() {
    int rows;
    printf("Welcome to Printing Patterns\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Here is the right half Pyramid:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\nHere is the reverse right half Pyramid:\n");
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < rows - i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}