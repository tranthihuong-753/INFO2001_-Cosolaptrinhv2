#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int student_id;
    float score;
};

void writeData() {
    struct Student students[] = {
        {"John Doe", 123456, 8.5},
        {"Jane Smith", 789012, 9.0},
        {"Bob Johnson", 345678, 7.8}
    };

    FILE *file = fopen("students.bin", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(students, sizeof(struct Student), sizeof(students) / sizeof(struct Student), file);
    fclose(file);

    printf("Data written to file successfully.\n");
}

void readData() {
    struct Student students[3];

    FILE *file = fopen("students.bin", "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    fread(students, sizeof(struct Student), sizeof(students) / sizeof(struct Student), file);
    fclose(file);

    printf("Data read from file:\n");
    for(int i = 0; i < sizeof(students) / sizeof(struct Student); i++) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Student ID: %d\n", students[i].student_id);
        printf("Score: %.2f\n", students[i].score);
        printf("---------------------\n");
    }
}

int main() {
    writeData();
    readData();

    return 0;
}
