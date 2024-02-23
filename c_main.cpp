#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int M = 15; // namu darbu uzduociu kiekis kai generuojama atsitiktinai

struct stud {
    string vard, pav;
    double* rez_nd;
    double rez_egz;
    double vid;
    double med;
    int m_size; // Size of rez_nd array
};

void pasirinkimas1(stud* grupe, int n);
void pasirinkimas2(stud* grupe, int n);
void pasirinkimas3(stud* grupe, int n);
void printrez(stud* grupe, int n);
void MedianaVidurkis(stud& grupe);

int main() {
    srand(time(NULL));
    stud* grupe = nullptr;
    char pasirinkimas;
    int n;
    do {
        do {
            cout << "1 - Ivesti duomenis ranka\n2 - Generuoti pazymius\n3 - Generuoti ir pazymius, ir studentu vardus, ir pavardes\n4 - Baigti darba\nPasirinkimas: ";
            cin >> pasirinkimas;
        } while (!(pasirinkimas == '1' || pasirinkimas == '2' || pasirinkimas == '3' || pasirinkimas == '4'));

        if (pasirinkimas=='1') {
            cout << "Kiek studentu yra grupeje? ";
            cin >> n;
            grupe = new stud[n];
            pasirinkimas1(grupe, n);
        }
        else if (pasirinkimas=='2') {
            cout << "Kiek studentu yra grupeje? ";
            cin >> n;
            grupe = new stud[n];
            pasirinkimas2(grupe, n);
        }
        else if (pasirinkimas=='3') {
            cout << "Kiek studentu yra grupeje? ";
            cin >> n;
            grupe = new stud[n];
            pasirinkimas3(grupe, n);
        }
        else if (pasirinkimas=='4') break;
        else cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";

        delete[] grupe;
    } while (pasirinkimas != '4');
    return 0;
}

void pasirinkimas1(stud* grupe, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "studento vardas ir pavarde: ";
        cin >> grupe[i].vard >> grupe[i].pav;
        cout << "studento egzamino rezultatas(1-10): ";
        cin >> grupe[i].rez_egz;
        cout << "Namu darbu kiekis: ";
        int m;
        cin >> m;
        grupe[i].m_size = m;
        grupe[i].rez_nd = new double[m];
        for (int j = 0; j < m; ++j) {
            cout << j + 1 << "-os uzduoties rezultatas(1-10): ";
            cin >> grupe[i].rez_nd[j];
        }
        MedianaVidurkis(grupe[i]);
        delete[] grupe[i].rez_nd;
    }
    printrez(grupe, n);
}

void pasirinkimas2(stud* grupe, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "studento vardas ir pavarde: ";
        cin >> grupe[i].vard >> grupe[i].pav;
        grupe[i].rez_egz = 1 + rand() % 10;;
        int m = 1 + rand() % M;
        grupe[i].m_size = m; // 
        grupe[i].rez_nd = new double[m]; 
        for (int j = 0; j < m; ++j) {
            grupe[i].rez_nd[j] = 1 + rand() % 10;
        }
        MedianaVidurkis(grupe[i]);
        delete[] grupe[i].rez_nd;
    }
    printrez(grupe, n);
}

void pasirinkimas3(stud* grupe, int n) {
    for (int i = 0; i < n; ++i) {
        grupe[i].vard = "Vardas" + to_string(1 + rand() % 10);
        grupe[i].pav = "Pavarde" + to_string(1 + rand() % 10);
        grupe[i].rez_egz = 1 + rand() % 10;;
        int m = 1 + rand() % M;
        grupe[i].m_size = m;
        grupe[i].rez_nd = new double[m];
        for (int j = 0; j < m; ++j) {
            grupe[i].rez_nd[j] = 1 + rand() % 10;
        }
        MedianaVidurkis(grupe[i]);
        delete[] grupe[i].rez_nd;
    }
    printrez(grupe, n);
}

void printrez(stud* grupe, int n) {
    char vid_med;
    double a = -1;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do {
        cin >> vid_med;
    } while (vid_med!='v'&&vid_med!='m');
    cout << "Vardas        Pavarde       "; if (vid_med == 'v') cout <<"Galutinis (Vid.)"<< endl;
                                            else if (vid_med == 'm') cout <<"Galutinis (Med.)"<< endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        if (vid_med == 'v') a = grupe[i].vid;
        else if (vid_med == 'm') a = grupe[i].med;
        double galutinis = (0.4 * a) + (0.6 * grupe[i].rez_egz);
        cout << left << setw(14) << grupe[i].vard << left << setw(14) << grupe[i].pav << left << setw(20) << setprecision(2) << galutinis << endl;
    }
    cout << "--------------------------------------------\n";
    cout << endl;
}

void MedianaVidurkis(stud& grupe) {
    // Sort rez_nd array
    sort(grupe.rez_nd, grupe.rez_nd + grupe.m_size);

    // mediana
    int m_size = grupe.m_size;
    if (m_size % 2 != 0)
        grupe.med = grupe.rez_nd[m_size / 2];
    else
        grupe.med = (grupe.rez_nd[m_size / 2 - 1] + grupe.rez_nd[m_size / 2]) / 2.0;

    // vidurkis
    double sum = 0;
    for (int i = 0; i < m_size; i++) {
        sum += grupe.rez_nd[i];
    }
    grupe.vid = sum / m_size;
}
