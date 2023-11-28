#include <stdio.h>

#define MAX_STUDENTS 100

int main() {
    int n;
    float scores[MAX_STUDENTS];
    float sum = 0.0;
    float average;

    printf("so luong sinh vien : ");
    scanf("%d", &n);

    printf("nhap diem cua sinh vien :\n");
    for (int i = 0; i < n; i++) {
        printf("diem cua sinh vien  %d: ", i + 1);
        scanf("%f", &scores[i]);
        sum += scores[i];  
    }

    average = sum / n; 

    printf("diem trung binh : %.2f\n", average);

    return 0;
}
