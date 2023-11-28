#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100 

struct Student {
    char name[50];
    int id;
    float score;
};

void displayStudent(struct Student student) {
    printf("Ten: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Ðiem: %.2f\n", student.score);
   
}

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

int binarySearchByName(struct Student students[], int n, const char *name) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (strcmp(students[mid].name, name) == 0) {
            return mid;  // Tr? v? ch? s? n?u t?m th?y
        } else if (strcmp(students[mid].name, name) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  
}

int linearSearchById(struct Student students[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("Nhap so luong sinh vien : ");
    scanf("%d", &numStudents);

  
    for (int i = 0; i < numStudents; i++) {
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        printf("Ten: ");
        scanf("%s", students[i].name);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Ðiem: ");
        scanf("%f", &students[i].score);
    }

   
    bubbleSort(students, numStudents);

  
    printf("Danh sach sinh vien sau khi xep theo ten :\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Sinh vien %d:\n", i + 1);
        displayStudent(students[i]);
    }

   
    char searchName[50];
    printf("Nhap ten sinh vien can tim kiem : ");
    scanf("%s", searchName);

    int searchResult = binarySearchByName(students, numStudents, searchName);
    if (searchResult != -1) {
        printf("sinh vien duoc tim thay :\n");
        displayStudent(students[searchResult]);
    } else {
        printf("Khong tim thay sinh vien .\n");
    }

   
    int searchId;
    printf("Nhap ID sinh vien can tim : ");
    scanf("%d", &searchId);

    searchResult = linearSearchById(students, numStudents, searchId);
    if (searchResult != -1) {
        printf("Sinh vien duoc tim thay:\n");
        displayStudent(students[searchResult]);
    } else {
        printf("Khong tim thay sinh vien .\n");
    }

    return 0;
}
