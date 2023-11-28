#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int employeeId;
    char name[50];
    char position[50];
    float salary;
};

void displayEmployee(struct Employee employee) {
    printf("Ma nhan vien : %d\n", employee.employeeId);
    printf("Ten: %s\n", employee.name);
    printf("Chuc vu : %s\n", employee.position);
    printf("Luong: %.2f\n", employee.salary);
    printf("--------------------\n");
}

int findEmployeeIndex(struct Employee employees[], int numEmployees, int employeeId) {
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].employeeId == employeeId) {
            return i; 
        }
    }

    return -1;  
}

void addEmployee(struct Employee employees[], int *numEmployees) {
    if (*numEmployees == MAX_EMPLOYEES) {
        printf("Danh sach nhan vien da day ko the them nhan vien moi .\n");
        return;
    }

    struct Employee newEmployee;

    printf("Nhap thong tin cho nhan vien moi:\n");
    printf("Ma nhan vien : ");
    scanf("%d", &newEmployee.employeeId);

   
    int existingIndex = findEmployeeIndex(employees, *numEmployees, newEmployee.employeeId);
    if (existingIndex != -1) {
        printf("Ma nhan vien da ton tai .\n");
        return;
    }

    printf("Ten: ");
    scanf("%s", newEmployee.name);
    printf("Chuc vu: ");
    scanf("%s", newEmployee.position);
    printf("Luong : ");
    scanf("%f", &newEmployee.salary);

    employees[*numEmployees] = newEmployee;
    (*numEmployees)++;

    printf("them nhan vien thanh cong .\n");
}

void deleteEmployee(struct Employee employees[], int *numEmployees, int employeeId) {
    int employeeIndex = findEmployeeIndex(employees, *numEmployees, employeeId);
    if (employeeIndex == -1) {
        printf("Không tim thay nhan vien co ma nhan vien %d.\n", employeeId);
        return;
    }

   
    for (int i = employeeIndex; i < *numEmployees - 1; i++) {
        employees[i] = employees[i + 1];
    }

    (*numEmployees)--;
    printf("Xoa nhan vien thanh cong .\n");
}

void displayAllEmployees(struct Employee employees[], int numEmployees) {
    if (numEmployees == 0) {
        printf("Danh sach nhan vien mo rong .\n");
        return;
    }

    printf("Danh sach nhan vien :\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Nhan vien  %d:\n", i + 1);
        displayEmployee(employees[i]);
    }
}

void bubbleSortBySalary(struct Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = 0; j < numEmployees - i - 1; j++) {
            if (employees[j].salary > employees[j + 1].salary) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    int choice;
    do {
        printf("Quan li nhan su \n");
        printf("1. Them nhan vien \n");
        printf("2. Xoa nhan vien \n");
        printf("3. Hien thi danh sach \n");
        printf("4. Sap xep nhan vien theo luong . Thoat\n");
        printf("Nhap lua chon : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2: {
                int employeeId;
                printf("Nhap ma nhan vien can xoa : ");
                scanf("%d", &employeeId);
                deleteEmployee(employees, &numEmployees, employeeId);
                break;
            }
            case 3:
                displayAllEmployees(employees, numEmployees);
                break;
            case 4:
                bubbleSortBySalary(employees, numEmployees);
                printf("Danh sach nhan vien duoc sap xep theo luong \n");
                break;
            case 5:
                printf("Chuong trinh ket thuc \n");
                break;
            default:
                printf("Lua ch?n ko hop le \n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}
