#include <iostream>

using namespace std;


class Employee {
public:
    virtual void calculateSalary() = 0;
};

class PermanentEmployee : public Employee {
private:
    int monthlySalary;

public:
    PermanentEmployee(int salary) {
        monthlySalary = salary;
    }

    void calculateSalary() {
        cout << "Monthly Salary: " << monthlySalary << endl;
    }
};

class VisitingEmployee : public Employee {
private:
    int hours;
    int rate;

public:
    VisitingEmployee(int h, int r) {
        hours = h;
        rate = r;
    }

    void calculateSalary() {
        cout << "Visiting Employee Salary: "
             << hours * rate << endl;
    }
};

int main() {
    int salary, hours, rate;

    cout << "Enter permanent employee salary: ";
    cin >> salary;

    cout << "Enter visiting employee hours: ";
    cin >> hours;
    
    cout << "Enter hourly rate: ";
    cin >> rate;
    
    PermanentEmployee p(salary);
    VisitingEmployee v(hours, rate);
    
    p.calculateSalary();
    v.calculateSalary();
    
    return 0;
    
}