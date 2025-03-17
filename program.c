#include <stdio.h>
#include <string.h>

// Define a structure to store student details
struct Student {
    char name[50];
    int rollNumber;
    float marks[5]; // Marks for 5 subjects
    float totalMarks;
    char grade;
};

// Function to calculate total marks and grade
void calculateGrade(struct Student *student) {
    student->totalMarks = 0;
    for (int i = 0; i < 5; i++) {
        student->totalMarks += student->marks[i];
    }

    if (student->totalMarks >= 450) {
        student->grade = 'A';
    } else if (student->totalMarks >= 400) {
        student->grade = 'B';
    } else if (student->totalMarks >= 350) {
        student->grade = 'C';
    } else if (student->totalMarks >= 300) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}

// Function to display student details
void displayStudent(struct Student student) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Total Marks: %.2f\n", student.totalMarks);
    printf("Grade: %c\n", student.grade);
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }

        // Calculate total marks and grade
        calculateGrade(&students[i]);
    }

    // Display all student details
    printf("\n--- Student Report ---\n");
    for (int i = 0; i < n; i++) {
        displayStudent(students[i]);
    }

    return 0;
}3