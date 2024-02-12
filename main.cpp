#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct stud {
    string vard, pav;
    int* rez_nd;
    int rez_egz;
    double vid;
};

int main() {
    int n = 0;

    cout << "Kiek studentų yra grupėje? ";
    cin >> n;

    stud* grupe = new stud[n];

    for (int i = 0; i < n; i++) {
        cout << "Studento vardas ir pavarde: ";
        cin >> grupe[i].vard >> grupe[i].pav;
        cout << endl;

        cout << "Studento egzamino rezultatas: ";
        cin >> grupe[i].rez_egz;
        cout << endl;

        cout << "Studento namu darbu uzduociu kiekis: ";
        int m;
        cin >> m;

        grupe[i].rez_nd = new int[m];

        int sum = 0;
        for (int j = 0; j < m; j++) {
            cout << "Studento " << grupe[i].vard << " " << grupe[i].pav << " " << j + 1 << "-os uzduoties rezultatas(1-10): ";
            cin >> grupe[i].rez_nd[j];
            sum += grupe[i].rez_nd[j];
        }
        grupe[i].vid = (double)sum / m;
    }

cout << "Vardas        Pavarde       Galutinis (Vid.)" << endl;
cout << "--------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        double galutinis=(0.4*(grupe[i].vid))+(0.6*(grupe[i].rez_egz));
        cout <<left<<setw(14)<< grupe[i].vard <<left<< setw(14) << grupe[i].pav <<left<< setw(14) << setprecision(2) << galutinis << endl;
        delete[] grupe[i].rez_nd;
    }
    delete[] grupe;

    return 0;
}
