#include <stdio.h>

// Defining the Date structure
struct Date {
    int dd, mm, yy;
};

// Defining the Employee structure
struct Employee {
    int Empno;
    char EmpName[50];
    struct Date hiredate;
    float BasicSalary;
    float NetSalary;
};

// Function to calculate Netsalary
void calculateNetSalary(struct Employee *emp) {
    float DA = 0.4 * emp->BasicSalary;
    float TA = 0.1 * emp->BasicSalary;
    float PF = 0.05 * emp->BasicSalary;

    emp->NetSalary = emp->BasicSalary + DA + TA - PF;
}

// Function to accept employee data
void AcceptEmployeeData(struct Employee *emp) {
    printf("Please Enter Employee Number: ");
    scanf("%d", &emp->Empno);

    printf("Please Enter Employee Name: ");
    scanf("%s", emp->EmpName);

    printf("Please Enter Hire Date (DD MM YY): ");
    scanf("%d %d %d", &emp->hiredate.dd, &emp->hiredate.mm, &emp->hiredate.yy);

    printf("Please Enter Basic Salary: ");
    scanf("%f", &emp->BasicSalary);

    calculateNetSalary(emp);
}

// Function to display employee data
void DisplayEmployeeData(struct Employee emp) {
    printf("\nEmployee Number: %d\n", emp.Empno);
    printf("Employee Name: %s\n", emp.EmpName);
    printf("Hire Date: %02d/%02d/%02d\n", emp.hiredate.dd, emp.hiredate.mm, emp.hiredate.yy);
    printf("Basic Salary: %.2f\n", emp.BasicSalary);
    printf("Net Salary: %.2f\n", emp.NetSalary);
}

int main() {
    int n;
    printf("Please Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("\nPlease Enter details for Employee %d:\n", i + 1);
        AcceptEmployeeData(&emp[i]);
    }

    printf("\nBelow are the Employee Details:\n");
    for (int i = 0; i < n; i++) {
        DisplayEmployeeData(emp[i]);
    }

    return 0;
}