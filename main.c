#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 100

// Structure to represent a Task
struct Task {
    int id;
    char title[100];
    char description[200];
    char deadline[11];
    char status[30];
};

// Array to store the tasks and the number of tasks
struct Task tasks[MAX_TASKS];
int numTasks = 0;

// Function to add a new task
void addTask() {
    // Check if the maximum task limit has been reached
    if (numTasks >= MAX_TASKS) {
        printf("Task limit reached!\n");
        return;
    }

    // Create a new task and read its attributes from the user
    struct Task newTask;
    printf("Enter task title:\n ");
    scanf("%s", newTask.title);
    printf("Enter task description:\n ");
    scanf("%s", newTask.description);
    printf("Enter task deadline yyyy/mm/dd:\n");
    scanf("%10s", newTask.deadline);
    printf("Enter task status:\n ");
    scanf("%s", newTask.status);

    // Assign a unique ID to the new task and add it to the tasks array
    newTask.id = numTasks + 1;
    tasks[numTasks] = newTask;
    numTasks++;

    printf("Task added successfully!\n");
}
// Function to add multiple tasks at once
void addMultipleTasks() {
    int num;
    printf("Enter the number of tasks to add: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        addTask();
    }

    printf("All tasks added successfully!\n");
}
// Function to display all the tasks
void displayTasks() {
    printf("Task List:\n");

    // Iterate over all the tasks and print their attributes
    for (int i = 0; i < numTasks; i++) {

        printf("ID: %d\n", tasks[i].id);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Deadline: %s", tasks[i].deadline);
        printf("Status: %s\n", tasks[i].status);
        printf("----------------------------------------\n");
    }
}

// Function to modify a tasks description
void modifyDesc() {
    int taskId;
    printf("Enter the ID of the task to modify: ");
    scanf("%d", &taskId);

    // Search for the task with the given ID and modify its attributes if found
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            printf("Task found! Enter new description:\n");
            scanf("%s", tasks[i].description);
            printf("Task modified successfully!\n");

        return;
        }
    }

    printf("Task with ID %d not found!\n", taskId);
}
// Function to modify a task
void modifyStatus() {
    int taskId;
    printf("Enter the ID of the task to modify: ");
    scanf("%d", &taskId);

    // Search for the task with the given ID and modify its attributes if found
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            printf("Task found! Enter new status:\n");
            scanf("%s", tasks[i].status);
            printf("Task modified successfully!\n");
            return;
        }
    }

    printf("Task with ID %d not found!\n", taskId);
}
// Function to modify a task
void modifyDeadline() {
    int taskId;
    printf("Enter the ID of the task to modify: ");
    scanf("%d", &taskId);

    // Search for the task with the given ID and modify its attributes if found
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            printf("Task found! Enter new deadline:\n");
            scanf("%s", tasks[i].deadline);
            printf("Task modified successfully!\n");
            return;
        }
    }

    printf("Task with ID %d not found!\n", taskId);
}

// Function to delete a task
void deleteTask() {
    int taskId;
    printf("Enter the ID of the task to delete: ");
    scanf("%d", &taskId);

    // Search for the task with the given ID and delete it from the tasks array if found
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            // Shift all the tasks after the deleted task to the left by one position
            for (int j = i; j < numTasks; j++) {
                tasks[j] = tasks[j + 1];
            }
            numTasks--;
            printf("Task deleted successfully!\n");
            return;
        }
    }

    printf("Task with ID %d not found!\n", taskId);
}

// Function to search for a task by ID
void searchById() {
    int taskId;
    printf("Enter the ID of the task to search: ");
    scanf("%d", &taskId);

    // Search for the task with the given ID and print its attributes if found
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            printf("Task found!\n");
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Status: %s\n", tasks[i].status);
            return;
        }
    }

    printf("Task with ID %d not found!\n", taskId);
}

// Function to search for tasks by title
void searchByTitle() {
    char title[100];
    printf("Enter the title of the task to search: ");
    scanf("%s", title);

    bool found = false; // Initialize the boolean variable to false

    // Search for tasks with the given title and print their attributes if found
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].title, title) == 0) {
            printf("Task found!\n");
            printf("ID: %d\n", tasks[i].id);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Status: %s\n", tasks[i].status);
            found = true; // Set the boolean variable to true
        }
    }

    if (found == false) {
        printf("Task with title '%s' not found!\n", title);
    }
}
// Function to sort tasks by alphabetical order based on the title
void sortTasksTitle() {
    for (int i = 0; i < numTasks - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numTasks; j++) {
            if (strcmp(tasks[j].title, tasks[minIndex].title) < 0) {
                minIndex = j;
            }
        }

        // Swap the tasks if the minimum task is not at its correct position
        if (minIndex != i) {
            struct Task temp = tasks[i];
            tasks[i] = tasks[minIndex];
            tasks[minIndex] = temp;
        }
    }

    printf("Tasks sorted by title!\n");
}
// Function to compare two tasks by deadline
int compareTasksByDeadline(const struct Task task1, const struct Task task2) {
    return strcmp(task1.deadline, task2.deadline);
}

// Selection sort to sort tasks array by deadline
void sortByDeadline() {
    for (int i = 0; i < numTasks - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numTasks; j++) {
            if (compareTasksByDeadline(tasks[j], tasks[minIndex]) < 0) {
                minIndex = j;
            }
        }

        // Swap the tasks if the minimum task is not at its correct position
        if (minIndex != i) {
            struct Task temp = tasks[i];
            tasks[i] = tasks[minIndex];
            tasks[minIndex] = temp;
        }
    }
}
void totalTasks() {
    printf("Total number of tasks: %d\n", numTasks);
}
// Function to display completed and incompleted  tasks
void taskCompletedIncompleted() {

    int completeCount = 0;
    int incompleteCount = 0;

    // Count the number of complete and incomplete tasks
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].status, "finalisee") == 0) {
            completeCount++;
        } else {
            incompleteCount++;
        }
    }

    printf("Number of completed tasks: %d\n", completeCount);
    printf("Number of incompleted tasks: %d\n", incompleteCount);
}
char todayDate[11];
// Function to check if a given deadline is within the next 3 days
bool isWithin3Days(const char deadline[11]) {
    time_t now;
    struct tm today_tm;
    time(&now); // Get the current time (in seconds since Jan 1, 1970)
    // Convert the current time to a local date and time representation
    localtime_s(&today_tm, &now);
    // Extract year, month, and day from the current local time
    int todayYear = today_tm.tm_year + 1900; // Adjust year to get the actual year (e.g., 2023)
    int todayMonth = today_tm.tm_mon + 1; // Adjust month (0-11) to (1-12)
    int todayDay = today_tm.tm_mday; // Get the day of the month

    int deadlineYear, deadlineMonth, deadlineDay; // Declare variables for deadline components

    // Parse the deadline string in the format "YYYY/MM/DD" and extract components
    sscanf(deadline, "%4d/%2d/%2d", &deadlineYear, &deadlineMonth, &deadlineDay);

    // Calculate the date difference in days
    int daysDifference =
        (deadlineYear - todayYear) * 365 + // Calculate year difference in days (approximation)
        (deadlineMonth - todayMonth) * 30 + // Calculate month difference in days (approximation)
        (deadlineDay - todayDay); // Calculate day difference

    // Check if the calculated difference is between 0 and 3 days (inclusive)
    return (daysDifference >= 0 && daysDifference <= 3);
}

// Function to print tasks with deadlines within 3 days of today
void printTasksWithin3Days() {
    printf("Tasks with deadlines within 3 days:\n");

    for (int i = 0; i < numTasks; i++) {
        if (isWithin3Days(tasks[i].deadline)) {
            printf("Task ID: %d\n", tasks[i].id);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Status: %s\n", tasks[i].status);
            printf("----------------------------------------\n");
        }
    }
}

//Function to display deadline of tasks
void displayDaysUntilDeadline() {
    time_t now, deadlineTime;
    int daysRemaining, year, month, day;

    // Get the current time since epoch
    now = time(NULL);

    printf("Days until deadline for each task:\n");

    // Iterate over all the tasks and calculate the days remaining for each
    for (int i = 0; i < numTasks; i++) {
        // Extract the year, month, and day from the deadline string
        sscanf(tasks[i].deadline, "%4d/%2d/%2d", &year, &month, &day);

        // Calculate the time since epoch for the deadline
        struct tm deadlineTm = {0};
        deadlineTm.tm_year = year - 1900;
        deadlineTm.tm_mon = month - 1;
        deadlineTm.tm_mday = day;
        deadlineTime = mktime(&deadlineTm);

        // Calculate the number of days remaining
        daysRemaining = (int)((deadlineTime - now) / (60 * 60 * 24));

        printf("Task ID: %d - %s: %d days remaining\n", tasks[i].id, tasks[i].title, daysRemaining);
    }
}
// Main function to run the program
int main() {
    int choice;

    // Display the menu and process user's choice until they choose to exit
    do {
        printf("\nToDo List Management\n");
        printf("1. Add a new task\n");
        printf("2. Add multiple tasks\n");
        printf("3. Display options\n");
        printf("4. Modify a task\n");
        printf("5. Delete a task\n");
        printf("6. Search\n");
        printf("7. Display statistics\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the user's choice by calling the appropriate functions
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                addMultipleTasks();
                break;
            case 3:{
                int displayChoice;
                printf("\nDisplay Options\n");
                printf("1. Display all tasks\n");
                printf("2. Sort tasks by title\n");
                printf("3. Sort tasks by deadline\n");
                printf("4. Print tasks within 3 days\n");
                printf("Enter your choice: ");
                scanf("%d", &displayChoice);

                switch (displayChoice) {
                    case 1:
                        displayTasks();
                        break;
                   case 2:
                        sortTasksTitle();
                        displayTasks();
                        break;
                    case 3:
                        sortByDeadline();
                        displayTasks();
                        break;
                    case 4:
                        printTasksWithin3Days();
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;
            }
            case 4:{
                int displayChoice;
                printf("\nDisplay Options\n");
                printf("1. Modify by description\n");
                printf("2. Modify by status\n");
                printf("3. Modify by deadline\n");
                printf("Enter your choice: ");
                scanf("%d", &displayChoice);
                switch (displayChoice) {
                    case 1:
                        modifyDesc();
                        break;
                   case 2:
                        modifyStatus();
                        break;
                    case 3:
                        modifyDeadline();
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
               break;
            }
            case 5:
                deleteTask();
                break;
            case 6:{
                int displayChoice;
                printf("\nDisplay Options\n");
                printf("1. Search by ID\n");
                printf("2. Search by title\n");
                printf("Enter your choice: ");
                scanf("%d", &displayChoice);
                switch (displayChoice) {
                    case 1:
                        searchById();
                        break;
                   case 2:
                        searchByTitle();
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;
            }
           case 7: {
                int displayChoice;
                printf("\nStats\n");
                printf("1. total tasks\n");
                printf("2. Completed incompleted tasks\n");
                printf("3. days until deadline\n");
                printf("Enter your choice: ");
                scanf("%d", &displayChoice);

                switch (displayChoice) {
                    case 1:
                        totalTasks();
                        break;
                  case 2:
                        taskCompletedIncompleted();
                        break;
                  case 3:
                        displayDaysUntilDeadline();
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;
            }
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (choice != 8);

        return 0;
}


