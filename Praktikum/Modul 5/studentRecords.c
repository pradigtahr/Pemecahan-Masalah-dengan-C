#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for student record
typedef struct Student {
    int id;
    char *name;
    int math_marks;
    int physics_marks;
    int chemistry_marks;
    struct Student *next; // Pointer to the next node
} Student;

// Function to add a new student record
void addStudent(Student **head, int id, char *name, int math_marks, int physics_marks, int chemistry_marks) {
    Student *new_student = (Student *)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    new_student->id = id;
    new_student->name = strdup(name); // Allocate memory and copy name
    new_student->math_marks = math_marks;
    new_student->physics_marks = physics_marks;
    new_student->chemistry_marks = chemistry_marks;
    new_student->next = NULL;

    if (*head == NULL) {
        *head = new_student;
    } else {
        Student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_student;
    }
}

// Function to display all student records
void displayStudents(Student *head) {
    printf("\nStudent Records:\n");
    Student *current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Math: %d, Physics: %d, Chemistry: %d\n",
               current->id, current->name, current->math_marks,
               current->physics_marks, current->chemistry_marks);
        current = current->next;
    }
    printf("\n");
}

// Function to search for a student record by ID
void searchStudent(Student *head, int search_id) {
    Student *current = head;
    int found = 0;
    while (current != NULL) {
        if (current->id == search_id) {
            printf("Student found:\n");
            printf("ID: %d, Name: %s, Math: %d, Physics: %d, Chemistry: %d\n",
                   current->id, current->name, current->math_marks,
                   current->physics_marks, current->chemistry_marks);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("Student with ID %d not found.\n", search_id);
    }
}

// Function to delete a student record by ID
void deleteStudent(Student **head, int id) {
    Student *current = *head;
    Student *prev = NULL;

    // Search for the node with the given ID
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    // If the node is found
    if (current != NULL) {
        // If the node to be deleted is the head node
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        // Free memory allocated for the node
        free(current->name);
        free(current);
        printf("Student with ID %d deleted successfully.\n", id);
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to insert a new student record in the middle of the structure
void insertInMiddle(Student **head, int id, char *name, int math_marks, int physics_marks, int chemistry_marks, int position) {
    Student *new_student = (Student *)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    new_student->id = id;
    new_student->name = strdup(name); // Allocate memory and copy name
    new_student->math_marks = math_marks;
    new_student->physics_marks = physics_marks;
    new_student->chemistry_marks = chemistry_marks;

    if (position == 1 || *head == NULL) {
        new_student->next = *head;
        *head = new_student;
    } else {
        Student *current = *head;
        int count = 1;
        while (count < position - 1 && current->next != NULL) {
            current = current->next;
            count++;
        }
        new_student->next = current->next;
        current->next = new_student;
    }
}

// Function to calculate and display the average marks of all students
void calculateAverage(Student *head) {
    int num_students = 0;
    int total_math = 0, total_physics = 0, total_chemistry = 0;
    Student *current = head;
    while (current != NULL) {
        num_students++;
        total_math += current->math_marks;
        total_physics += current->physics_marks;
        total_chemistry += current->chemistry_marks;
        current = current->next;
    }

    printf("\nAverage marks:\n");
    printf("Math: %.2f\n", (float)total_math / num_students);
    printf("Physics: %.2f\n", (float)total_physics / num_students);
    printf("Chemistry: %.2f\n", (float)total_chemistry / num_students);
}

// Function to update the marks of a student by ID
void updateMarks(Student *head, int id, int math_marks, int physics_marks, int chemistry_marks) {
    Student *current = head;
    int found = 0;
    while (current != NULL) {
        if (current->id == id) {
            current->math_marks = math_marks;
            current->physics_marks = physics_marks;
            current->chemistry_marks = chemistry_marks;
            printf("Marks updated for student with ID %d.\n", id);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}


int main() {
    Student *head = NULL;
    int choice, search_id;

    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Insert Student in Middle\n");
        printf("6. Calculate Average Marks\n");
        printf("7. Update marks\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id, math_marks, physics_marks, chemistry_marks;
                char name[50];
                printf("Enter student ID: ");
                scanf("%d", &id);

                printf("Enter student name: ");
                getchar(); // Consume newline character from previous input
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character

                printf("Enter marks in Math: ");
                scanf("%d", &math_marks);

                printf("Enter marks in Physics: ");
                scanf("%d", &physics_marks);

                printf("Enter marks in Chemistry: ");
                scanf("%d", &chemistry_marks);

                addStudent(&head, id, name, math_marks, physics_marks, chemistry_marks);
                break;
            }
            case 2:
                displayStudents(head);
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &search_id);
                searchStudent(head, search_id);
                break;
            case 4: {
                int delete_id;
                printf("Enter student ID to delete: ");
                scanf("%d", &delete_id);
                deleteStudent(&head, delete_id);
                break;
            }
            case 5: {
                int id, math_marks, physics_marks, chemistry_marks, position;
                char name[50];
                printf("Enter position to insert: ");
                scanf("%d", &position);

                printf("Enter student ID: ");
                scanf("%d", &id);

                printf("Enter student name: ");
                getchar(); // Consume newline character from previous input
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character

                printf("Enter marks in Math: ");
                scanf("%d", &math_marks);

                printf("Enter marks in Physics: ");
                scanf("%d", &physics_marks);

                printf("Enter marks in Chemistry: ");
                scanf("%d", &chemistry_marks);

                insertInMiddle(&head, id, name, math_marks, physics_marks, chemistry_marks, position);
                break;
            }
            case 6:
                calculateAverage(head);
                break;
            case 7: {
                int id, math_marks, physics_marks, chemistry_marks;
                printf("Enter student ID to update marks: ");
                scanf("%d", &id);

                printf("Enter new marks in Math: ");
                scanf("%d", &math_marks);

                printf("Enter new marks in Physics: ");
                scanf("%d", &physics_marks);

                printf("Enter new marks in Chemistry: ");
                scanf("%d", &chemistry_marks);

                updateMarks(head, id, math_marks, physics_marks, chemistry_marks);
                break;
            }

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7);

    // Free dynamically allocated memory for student names
    Student *current = head;
    Student *next;
    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current);
        current = next;
    }

    return 0;
}
