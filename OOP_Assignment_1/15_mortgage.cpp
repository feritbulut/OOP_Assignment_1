#include <iostream>
#include <cmath>

using namespace std;

class Mortgage {
private:
    double loan;
    double rate;
    int years;

public:
    Mortgage(double l = 0.0, double r = 0.0, int y = 0) : loan(l), rate(r), years(y) {}

    void setLoan(double l) {
        loan = l;
    }

    void setRate(double r) {
        rate = r;
    }

    void setYears(int y) {
        years = y;
    }

    double monthpay() const {
        double monthly = rate / 12 / 100;
        int n = years * 12;
        double payment = (loan * monthly) / (1 - pow(1 + monthly, -n));
        return payment;
    }

    double totamount() const {
        return monthpay() * years * 12;
    }
};

int main() {
    double loanamount, interest;
    int numberyear;

    cout << "enter amount: ";
    cin >> loanamount;

    cout << "enter the annual interest rate : ";
    cin >> interest;

    cout << "enter the number years : ";
    cin >> numberyear;

    Mortgage mortgage(loanamount, interest, numberyear);

    cout << "\nmonth pay: $" << mortgage.monthpay() << endl;
    cout << "total amount: $" << mortgage.totamount() << endl;

    return 0;
}
