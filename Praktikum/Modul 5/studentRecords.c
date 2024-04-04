#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for student record
struct Student {
    int id;
    char *name;
    int math_marks;
    int physics_marks;
    int chemistry_marks;
};

// Function to add a new student record
void addStudent(struct Student **students, int *num_students) {
    *students = realloc(*students, (*num_students + 1) * sizeof(struct Student));
    if (*students == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    struct Student new_student;

    new_student.name = (char *)malloc(50 * sizeof(char)); // Allocate memory for name
    if (new_student.name == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter student ID: ");
    scanf("%d", &new_student.id);

    printf("Enter student name: ");
    getchar(); // Consume newline character from previous input
    fgets(new_student.name, 50, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0'; // Remove newline character

    printf("Enter marks in Math: ");
    scanf("%d", &new_student.math_marks);

    printf("Enter marks in Physics: ");
    scanf("%d", &new_student.physics_marks);

    printf("Enter marks in Chemistry: ");
    scanf("%d", &new_student.chemistry_marks);

    (*students)[*num_students] = new_student;
    (*num_students)++;
}

// Function to display all student records
void displayStudents(struct Student *students, int num_students) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < num_students; i++) {
        printf("ID: %d, Name: %s, Math: %d, Physics: %d, Chemistry: %d\n",
        students[i].id, students[i].name, students[i].math_marks,
        students[i].physics_marks, students[i].chemistry_marks);
    }
    printf("\n");
}

// Function to search for a student record by ID
void searchStudent(struct Student *students, int num_students, int search_id) {
    int found = 0;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == search_id) {
            printf("Student found:\n");
            printf("ID: %d, Name: %s, Math: %d, Physics: %d, Chemistry: %d\n",
            students[i].id, students[i].name, students[i].math_marks,
            students[i].physics_marks, students[i].chemistry_marks);
            // flag to know whether the student id is found or not
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", search_id);
    }
}

// Function to calculate and display the average marks of all students
void calculateAverage(struct Student *students, int num_students) {
    int total_math = 0, total_physics = 0, total_chemistry = 0;
    for (int i = 0; i < num_students; i++) {
        total_math += students[i].math_marks;
        total_physics += students[i].physics_marks;
        total_chemistry += students[i].chemistry_marks;
    }

    printf("\nAverage marks:\n");
    printf("Math: %.2f\n", (float)total_math / num_students);
    printf("Physics: %.2f\n", (float)total_physics / num_students);
    printf("Chemistry: %.2f\n", (float)total_chemistry / num_students);
}

int main() {
    struct Student *students = NULL;
    int num_students = 0;
    int choice, search_id;

    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Calculate Average Marks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students, &num_students);
                break;
            case 2:
                displayStudents(students, num_students);
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &search_id);
                searchStudent(students, num_students, search_id);
                break;
            case 4:
                calculateAverage(students, num_students);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    // Free dynamically allocated memory for student names
    for (int i = 0; i < num_students; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}
