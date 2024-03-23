#include <iostream>

using namespace std;

class Populationbilgi {
private:
    int total;
    int birth;
    int death;
public:

    Populationbilgi() {
        total = 0;
        birth = 0;
        death = 0;
    }


    void setPopulationveri(int population, int birthlar, int deathler) {
        total = population;
        birth = birthlar;
        death = deathler;
    }


    double birthrate() {
        return static_cast<double>(birth) / total;
    }

    double deathrate() {
        return static_cast<double>(death) / total;
    }


    void goster() {
        cout << "total: " << total << endl;
        cout << "birth: " << birth << endl;
        cout << "death: " << death << endl;
        cout << "birthrate: " << birthrate() << endl;
        cout << "deathrate: " << deathrate() << endl;
    }
};

int main() {
    int population, birthlar, deathler;


    cout << "total population: ";
    cin >> population;
    cout << "enter births: ";
    cin >> birthlar;
    cout << "enter deaths: ";
    cin >> deathler;


    Populationbilgi stats;


    stats.setPopulationveri(population, birthlar, deathler);


    cout << "\npopulation info:" << endl;
    stats.goster();

    return 0;
}
