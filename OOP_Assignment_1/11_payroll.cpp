#include <iostream>
using namespace std;

class payroll {
private:
    double hourlypay;
    double hoursworked;
    double totalpay;

public:
    payroll() : hourlypay(0.0), hoursworked(0.0), totalpay(0.0) {}

    void sethourlypay(double rate) {
        hourlypay = rate;
    }

    void sethoursworked(double hours) {

            hoursworked = hours;
    }

    void calculatetotalpay() {
        totalpay = hourlypay * hoursworked;
    }

    double gettotalpay() const {
        return totalpay;
    }
};

int main() {
    const int num_employees = 7;
    payroll employees[num_employees];
    double hours;

    for (int i = 0; i < num_employees; ++i) {
        cout << "enter hours:  " << i + 1 << ": ";
        cin >> hours;
        employees[i].sethoursworked(hours);
    }

    double payRate;
    cout << "\nenter pay rate:" << endl;
    for (int i = 0; i < num_employees; ++i) {
        cout << "employee " << i + 1 << ": ";
        cin >> payRate;
        employees[i].sethourlypay(payRate);
    }

    cout << "\ngross :" << endl;
    for (int i = 0; i < num_employees; ++i) {
        employees[i].calculatetotalpay();
        cout << "employee " << i + 1 << ": $" << employees[i].gettotalpay() << endl;
    }

    return 0;
}
