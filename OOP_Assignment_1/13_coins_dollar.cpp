#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class coindollar {
private:
    string launch;
public:

    coindollar() {
        srand(time(0));
        toss();
    }

    void toss() {

        int randomnum = rand() % 2;

        if (randomnum == 0) {
            launch = "heads";
        } else {
            launch = "tails";
        }
    }


    string getlaunch() {
        return launch;
    }

    int getvalue() {
        if (launch == "heads") {
            if (launch == "quarter") {
                return 25;
            } else if (launch == "dime") {
                return 10;
            } else {
                return 5;
            }
        }
        return 0;
    }
};

int main() {
    coindollar quarter, dime, nickel;
    double balance = 0.0;

    while (balance < 1.0) {

        quarter.toss();
        dime.toss();
        nickel.toss();

        cout << "quarter: " << quarter.getlaunch() << endl;
        cout << "dime: " << dime.getlaunch() << endl;
        cout << "nickel: " << nickel.getlaunch() << endl;

        balance += (quarter.getvalue() + dime.getvalue() + nickel.getvalue()) / 100.0;


        cout << "balance: $" << balance << endl;
        cout << "--------------------------" << endl;
    }


    if (balance == 1.0) {
        cout << "win " << endl;
    } else {
        cout << "lose " << endl;
    }

    return 0;
}
