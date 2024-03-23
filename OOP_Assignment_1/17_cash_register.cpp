#include <iostream>
#include <string>

using namespace std;

class inventory {
private:
    string name;
    double cost;
    int onhand;

public:
    inventory(string name, double c, int oh) {
        name = name;
        cost = c;
        onhand = oh;
    }

    string getname() {
        return name;
    }

    double getCost() {
        return cost;
    }

    int get() {
        return onhand;
    }

    void set(int oh) {
        onhand = oh;
    }
};


class cashregister {
private:
    inventory item;
    int quantity;

public:
    cashregister(inventory i, int q) : item(i) {
        quantity = q;
    }

    double calculatesub() {
        double unitPrice = item.getCost() * 1.30;
        return unitPrice * quantity;
    }

    double calctax(double subtotal) {
        return subtotal * 0.06;
    }

    void displayPurchase() {
        double subtotal = calculatesub();
        double tax = calctax(subtotal);
        double total = subtotal + tax;

        cout << "\n info:" << endl;
        cout << "-----------------" << endl;
        cout << "name: " << item.getname()  << endl;
        cout << "quantity: " << quantity << endl;
        cout << "total: $" << subtotal << endl;
        cout << "tax: $" << tax   << endl;
        cout << "total: $" << total << endl;

        int update = item.get() - quantity;
        item.set(update);
    }
};

int main() {
    inventory laptop("laptop", 800.0, 10);
    inventory phone("phone", 600.0, 15);
    inventory headphones("headphones", 100.0, 20);
    inventory tablet("tablet", 400.0, 5);

    cout << "1. laptop - $800.00" << endl;
    cout << "2. phone - $600.00" << endl;
    cout << "3. headphones - $100.00" << endl;
    cout << "4. tablet - $400.00" << endl;

    int choice, quantity;

    cout << "\nenter product: ";
    cin >> choice;

    cout << "enter quantity : ";
    cin >> quantity;

    cashregister* register1;
    switch (choice) {
        case 1:
            register1 = new cashregister(laptop, quantity);
            break;
        case 2:
            register1 = new cashregister(phone, quantity);
            break;
        case 3:
            register1 = new cashregister(headphones, quantity);
            break;
        case 4:
            register1 = new cashregister(tablet, quantity);
            break;
        default:
            cout << "invalid product" << endl;
            return 1;
    }

    register1->displayPurchase();

    delete register1;

    return 0;
}
