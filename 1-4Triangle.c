#include <stdio.h>

int main() {
    int rows = 4; // Number of rows in the triangle

    for (int i = 1; i <= rows; i++) { // Loop for rows
        for (int j = 1; j <= i; j++) { // Loop for columns
            printf("%d ", j); // Print the current number
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}