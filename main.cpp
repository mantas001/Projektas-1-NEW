#include <iostream>
#include <string>

using namespace std;

struct stud{
        string vard, pav;
        int rez_nd, rez_egz;
};

int main()
{
    int n=0;
    int m=0;

    stud *grupe = new stud [n];

    cout<<"Kiek studentų yra grupėje? ";
    cin >> n;

    delete [] grupe;

    grupe = new stud [n];

    for (int i=0; i<n; i++){
        cout << "Studento vardas ir pavarde: ";
        cin >> grupe[i].vard >> grupe[i].pav;
        cout << endl;

        cout << "Studento egzamino rezultatas: ";
        cin >> grupe[i].rez_egz;
        cout << endl;
    }
    return 0;
}
