#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct stud {
    string vard, pav;
    int* rez_nd;
    int rez_egz;
    double vid;
    double med;
};

int main() {
    int n = 0;
    cout << "Kiek studentų yra grupėje? ";
    cin >> n;

    
    stud* grupe = new stud[n];
    if(n>0)
    {
        for (int i = 0; i < n; i++) {
            cout << "Studento vardas ir pavarde: ";
            cin >> grupe[i].vard >> grupe[i].pav;
            cout << endl;
            do
            {
                cout << "Studento egzamino rezultatas: ";
                        cin >> grupe[i].rez_egz;
                        cout << endl;
            } while ((grupe[i].rez_egz< 0 || grupe[i].rez_egz> 10));

            int m;
            do
            {
            cout << "Studento " << grupe[i].vard << " " << grupe[i].pav << "namu darbu uzduociu kiekis: ";
            cin >> m;
            } while (m<0);

            grupe[i].rez_nd = new int[m+1];

            int sum = 0;
            for (int j = 0; j < m; j++) {
                do
                {
                cout << "Studento " << grupe[i].vard << " " << grupe[i].pav << " " << j + 1 << "-os uzduoties rezultatas(1-10): ";
                cin >> grupe[i].rez_nd[j];
                } while ((grupe[i].rez_nd[j]< 0 || grupe[i].rez_nd[j]> 10));
                
                sum += grupe[i].rez_nd[j];
            }

            //mediana
            double c=0;
            grupe[i].rez_nd[m]=grupe[i].rez_egz;
            for (int h = 0; h < m + 1; h++) {
                for (int j = 0; j < m; j++) {
                    if (grupe[i].rez_nd[j] > grupe[i].rez_nd[j + 1]) {
                        int temp = grupe[i].rez_nd[j];
                        grupe[i].rez_nd[j] = grupe[i].rez_nd[j + 1];
                        grupe[i].rez_nd[j + 1] = temp;
                    }
                }
            }
            if ((m + 1) % 2 != 0)
                grupe[i].med = grupe[i].rez_nd[(m + 1) / 2];
            else
                grupe[i].med = (grupe[i].rez_nd[m / 2] + grupe[i].rez_nd[(m + 1) / 2]) / 2.0;


            grupe[i].vid = (double)sum / m;
            cout << endl;
        }

        

        cout << "Vardas        Pavarde       Galutinis (Vid.) /  Galutinis (Med.)" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            double galutinis=(0.4*(grupe[i].vid))+(0.6*(grupe[i].rez_egz));
            double mediana=(double)grupe[i].med;
            cout <<left<<setw(14)<< grupe[i].vard <<left<< setw(14) << grupe[i].pav <<left<< setw(20) << setprecision(2) << galutinis <<left<< setw(14) << setprecision(2) << mediana << endl;
            delete[] grupe[i].rez_nd;
        }
    }
    delete[] grupe;

    return 0;
}
