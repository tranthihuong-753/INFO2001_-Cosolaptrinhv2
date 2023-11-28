#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int age;
    float score;
};

void displayStudent(struct Student student) {
    printf("Tên: %s\n", student.name);
    printf("Tu?i: %d\n", student.age);
    printf("Ði?m: %.2f\n", student.score);
    
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("si so sinh vien : ");
    scanf("%d", &numStudents);

   
    for (int i = 0; i < numStudents; i++) {
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        printf("ten: ");
        scanf("%s", students[i].name);
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        printf("Diem: ");
        scanf("%f", &students[i].score);
    }

    
    printf("Thong tin sinh vien :\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Sinh vien %d:\n", i + 1);
        displayStudent(students[i]);
    }

    
    int studentIndex;
    printf("Nhap chi so sinh vien can nhap thong tin : ");
    scanf("%d", &studentIndex);

    if (studentIndex >= 1 && studentIndex <= numStudents) {
        printf("Nhap thong tin cap nhat  %d:\n", studentIndex);
        printf("Ten: ");
        scanf("%s", students[studentIndex - 1].name);
        printf("Tuoi: ");
        scanf("%d", &students[studentIndex - 1].age);
        printf("Ðiem: ");
        scanf("%f", &students[studentIndex - 1].score);
    } else {
        printf("Chi so sinh vien khong hop le .\n");
    }

    
    printf("Thong tin sau cap nhat:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Sinh vien %d:\n", i + 1);
        displayStudent(students[i]);
    }

    return 0;
}
