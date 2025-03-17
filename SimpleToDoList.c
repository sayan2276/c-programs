#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_LENGTH 100

char tasks[MAX_TASKS][TASK_LENGTH];

int taskStatus[MAX_TASKS]; // 0 = incomplete, 1 = complete
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("To-do list is full!\n");
        return;
    }

    printf("Enter the task: ");
    getchar(); // Clear input buffer
    fgets(tasks[taskCount], TASK_LENGTH, stdin);
    tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0; // Remove newline character
    taskStatus[taskCount] = 0; // Mark as incomplete
    taskCount++;

    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks in the to-do list!\n");
        return;
    }

    printf("\n--- To-Do List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i], taskStatus[i] ? "Completed" : "Incomplete");
    }
}

void markTaskCompleted() {
    int taskNumber;

    viewTasks();
    if (taskCount == 0) return;

    printf("Enter the task number to mark as completed: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    taskStatus[taskNumber - 1] = 1;
    printf("Task marked as completed!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Simple To-Do List ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();a
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}