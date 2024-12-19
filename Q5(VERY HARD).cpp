// Hierarchical Inheritance for Employee Management System
// Objective
// Create a C++ program to simulate an employee management system using hierarchical inheritance. Design a base class Employee that stores basic details (name, ID, and salary). Create two derived classes:
// Manager: Add and calculate bonuses based on performance ratings.
// Developer: Add and calculate overtime compensation based on extra hours worked.
// The program should allow input for both types of employees and display their total earnings.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Employee {
protected:
    string name;
    int id;
    int salary;

public:
    Employee(string empName, int empID, int empSalary)
        : name(empName), id(empID), salary(empSalary) {}

    virtual void displayDetails() = 0;
};
class Manager : public Employee {
    int performanceRating;

public:
    Manager(string empName, int empID, int empSalary, int rating)
        : Employee(empName, empID, empSalary), performanceRating(rating) {}

    void displayDetails() override {
        int bonus = performanceRating * (salary * 0.1);
        int totalEarnings = salary + bonus;
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Manager\n";
        cout << "Base Salary: " << salary << "\n";
        cout << "Bonus: " << bonus << "\n";
        cout << "Total Earnings: " << totalEarnings << "\n";
    }
};

class Developer : public Employee {
    int extraHours;

public:
    Developer(string empName, int empID, int empSalary, int hours)
        : Employee(empName, empID, empSalary), extraHours(hours) {}

    void displayDetails() override {
        int overtimeCompensation = extraHours * 500;
        int totalEarnings = salary + overtimeCompensation;
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Developer\n";
        cout << "Base Salary: " << salary << "\n";
        cout << "Overtime Compensation: " << overtimeCompensation << "\n";
        cout << "Total Earnings: " << totalEarnings << "\n";
    }
};

int main() {
    int employeeType;
    cout << "Enter Employee Type (1 for Manager, 2 for Developer): ";
    cin >> employeeType;

    if (employeeType == 1) {
        string name;
        int id, salary, rating;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Performance Rating (1-5): ";
        cin >> rating;

        if (rating < 1 || rating > 5) {
            cout << "Invalid performance rating.\n";
            return 0;
        }

        Manager manager(name, id, salary, rating);
        manager.displayDetails();
    } else if (employeeType == 2) {
        string name;
        int id, salary, extraHours;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Extra Hours Worked: ";
        cin >> extraHours;

        if (extraHours < 0 || extraHours > 100) {
            cout << "Invalid number of extra hours.\n";
            return 0;
        }

        Developer developer(name, id, salary, extraHours);
        developer.displayDetails();
    } else {
        cout << "Invalid employee type.\n";
    }

    return 0;
}
