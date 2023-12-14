#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char student_id[10];
    float score;
};

void addStudent(struct Student student, FILE *file) {
    fwrite(&student, sizeof(struct Student), 1, file);
    printf("Student added successfully.\n");
}

void removeStudent(char student_id[10], FILE *file) {
    FILE *tempFile = fopen("temp.dat", "wb");
    struct Student student;
    int found = 0;

    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (strcmp(student.student_id, student_id) != 0) {
            fwrite(&student, sizeof(struct Student), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        printf("Student removed successfully.\n");
    } else {
        remove("temp.dat");
        printf("Student not found.\n");
    }
}

void updateStudent(char student_id[10], struct Student new_data, FILE *file) {
    FILE *tempFile = fopen("temp.dat", "wb");
    struct Student student;
    int found = 0;

    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (strcmp(student.student_id, student_id) == 0) {
            fwrite(&new_data, sizeof(struct Student), 1, tempFile);
            found = 1;
        } else {
            fwrite(&student, sizeof(struct Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        printf("Student updated successfully.\n");
    } else {
        remove("temp.dat");
        printf("Student not found.\n");
    }
}

void displayStudents(FILE *file) {
    struct Student student;

    while (fread(&student, sizeof(struct Student), 1, file)) {
        printf("Name: %s\n", student.name);
        printf("Student ID: %s\n", student.student_id);
        printf("Score: %.2f\n", student.score);
        printf("---------------------\n");
    }
}

int main() {
    FILE *file = fopen("students.dat", "ab+");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int choice;
    struct Student student;

    do {
        printf("1. Add student\n");
        printf("2. Remove student\n");
        printf("3. Update student\n");
        printf("4. Display students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]", student.name);
                printf("Enter student ID: ");
                scanf("%s", student.student_id);
                printf("Enter score: ");
                scanf("%f", &student.score);
                addStudent(student, file);
                break;
            case 2:
                printf("Enter student ID: ");
                scanf("%s", student.student_id);
                removeStudent(student.student_id, file);
                break;
            case 3:
                printf("Enter student ID: ");
                scanf("%s", student.student_id);
                printf("Enter new name: ");
                scanf(" %[^\n]", student.name);
                printf("Enter new score: ");
                scanf("%f", &student.score);
                updateStudent(student.student_id, student, file);
                break;
            case 4:
                displayStudents(file);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 0);

    fclose(file);

    return 0;
}
