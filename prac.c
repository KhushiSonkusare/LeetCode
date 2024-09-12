#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char employee_name[100];
    int employee_id;
    float salary;
    struct Employee *next;
};

struct Employee *first = NULL;

void create() {
    int n, i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        struct Employee *temp = (struct Employee *)malloc(sizeof(struct Employee));
        printf("Enter employee name: ");
        scanf("%s", temp->employee_name);
        printf("Enter employee ID: ");
        scanf("%d", &temp->employee_id);
        printf("Enter employee salary: ");
        scanf("%f", &temp->salary);
        temp->next = NULL;

        if (first == NULL) {
            first = temp;
        } else {
            struct Employee *ptr = first;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
}


void average_salary() {
    if (first == NULL) {
        printf("No employees in the list.\n");
        return;
    }

    struct Employee *ptr = first;
    int count = 0;
    float sum = 0;

    while (ptr != NULL) {
        sum += ptr->salary;
        count++;
        ptr = ptr->next;
    }

    float average = sum / count;
    printf("Average salary of all employees: %f\n", average);
}


struct Employee *sortedList() {
    if (first == NULL) {
        printf("No employees in the list.\n");
        return NULL;
    }

    struct Employee *sorted = NULL;
    struct Employee *ptr = first;

    while (ptr != NULL) {
        struct Employee *newNode = (struct Employee *)malloc(sizeof(struct Employee));
        strcpy(newNode->employee_name, ptr->employee_name);
        newNode->employee_id = ptr->employee_id;
        newNode->salary = ptr->salary;

        if (sorted == NULL || newNode->employee_id > sorted->employee_id) {
            newNode->next = sorted;
            sorted = newNode;
        } else {
            struct Employee *sortptr = sorted;
            while (sortptr->next != NULL && newNode->employee_id < sortptr->next->employee_id) {
                sortptr = sortptr->next;
            }
            newNode->next = sortptr->next;
            sortptr->next = newNode;
        }

        ptr = ptr->next;
    }

    return sorted;
}

void updateEmployeeName(char oldName[], char newName[]) {
    struct Employee *ptr = first;
    int updated = 0;

    while (ptr != NULL) {
        if (strcmp(ptr->employee_name, oldName) == 0) {
            strcpy(ptr->employee_name, newName);
            updated = 1;
        }
        ptr = ptr->next;
    }

    if (updated) {
        printf("Employee name updated successfully.\n");
    } else {
        printf("Employee not found with the given name.\n");
    }
}

void display(struct Employee *list) {
    struct Employee *ptr = list;
    while (ptr != NULL) {
        printf("Name: %s, ID: %d, Salary: %f\n", ptr->employee_name, ptr->employee_id, ptr->salary);
        ptr = ptr->next;
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Employee List\n");
        printf("2. Calculate Average Salary\n");
        printf("3. Create Sorted List by Employee ID (Descending Order)\n");
        printf("4. Update Employee Name\n");
        printf("5. Display Employee List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                average_salary();
                break;
            case 3:
                {
                    struct Employee *sorted = sortedList();
                    printf("Sorted Employee List by Employee ID (Descending Order):\n");
                    display(sorted);
                }
                break;
            case 4:
                {
                    char oldName[100], newName[100];
                    printf("Enter the old employee name: ");
                    scanf("%s", oldName);
                    printf("Enter the new employee name: ");
                    scanf("%s", newName);
                    updateEmployeeName(oldName, newName);
                }
                break;
            case 5:
                printf("Employee List:\n");
                display(first);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

