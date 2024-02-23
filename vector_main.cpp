#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 15; // namu darbu uzduociu kiekis kai generuojama atsitiktinai

struct stud {
    string vard, pav;
    vector<double> rez_nd;
    double rez_egz;
    double vid;
    double med;
};

void pasirinkimas1(vector<stud>& grupe);
void pasirinkimas2(vector<stud>& grupe);
void pasirinkimas3(vector<stud>& grupe);
void printrez(const vector<stud>& grupe);
void MedianaVidurkis(stud& grupe);

int main() {
    srand(time(NULL));
    vector<stud> grupe;
    char pasirinkimas;
    do {
        do {
            cout << "1 - Ivesti duomenis ranka\n2 - Generuoti pazymius\n3 - Generuoti ir pazymius, ir studentu vardus, ir pavardes\n4 - Baigti darba\nPasirinkimas: ";
            cin >> pasirinkimas;
        } while (!(pasirinkimas == '1' || pasirinkimas == '2' || pasirinkimas == '3' || pasirinkimas == '4'));

        if (pasirinkimas=='1') pasirinkimas1(grupe);
        else if (pasirinkimas=='2') pasirinkimas2(grupe);
        else if (pasirinkimas=='3') pasirinkimas3(grupe);
        else if (pasirinkimas=='4') break;
        else cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";

    } while (pasirinkimas != '4');
    return 0;
}

void pasirinkimas1(vector<stud>& grupe) {
    int n;
    cout << "Kiek studentu yra grupeje? ";
    cin >> n;
    grupe.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "studento vardas ir pavarde: ";
        cin >> grupe[i].vard >> grupe[i].pav;
        cout << "studento egzamino rezultatas(1-10): ";
        cin >> grupe[i].rez_egz;
        cout << "Namu darbu kiekis: ";
        int m;
        cin >> m;
        grupe[i].rez_nd.resize(m);
        for (int j = 0; j < m; ++j) {
            cout << j + 1 << "-os uzduoties rezultatas(1-10): ";
            cin >> grupe[i].rez_nd[j];
        }
        MedianaVidurkis(grupe[i]);
    }
    printrez(grupe);
}

void pasirinkimas2(vector<stud>& grupe) {
    int n;
    cout << "Kiek studentu yra grupeje? ";
    cin >> n;
    grupe.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "studento vardas ir pavarde: ";
        cin >> grupe[i].vard >> grupe[i].pav;
        grupe[i].rez_egz = 1 + rand() % 10;;
        int m = 1 + rand() % M;
        grupe[i].rez_nd.resize(m);
        for (int j = 0; j < m; ++j) {
            grupe[i].rez_nd[j] = 1 + rand() % 10;
        }
        MedianaVidurkis(grupe[i]);
    }
    printrez(grupe);
}

void pasirinkimas3(vector<stud>& grupe) {
    int n;
    cout << "Kiek studentu yra grupeje? ";

    cin >> n;
    grupe.resize(n);
    for (int i = 0; i < n; ++i) {
        grupe[i].vard = "Vardas" + to_string(1 + rand() % 10);
        grupe[i].pav = "Pavarde" + to_string(1 + rand() % 10);
        grupe[i].rez_egz = 1 + rand() % 10;;
        int m = 1 + rand() % M;
        grupe[i].rez_nd.resize(m);
        for (int j = 0; j < m; ++j) {
            grupe[i].rez_nd[j] = 1 + rand() % 10;
        }
        MedianaVidurkis(grupe[i]);
    }
    printrez(grupe);
}

void printrez(const vector<stud>& grupe) {
    char vid_med;
    double a = -1;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do{
    cin >> vid_med;
    }while(vid_med!='v'&&vid_med!='m');
    cout << "Vardas        Pavarde       "; if (vid_med == 'v') cout <<"Galutinis (Vid.)"<< endl;
                                            else if (vid_med == 'm') cout <<"Galutinis (Med.)"<< endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        if (vid_med == 'v') a = grupe[i].vid;
        else if (vid_med == 'm') a = grupe[i].med;
        double galutinis = (0.4 * a) + (0.6 * grupe[i].rez_egz);
        cout << left << setw(20) << grupe[i].vard << left << setw(20) << grupe[i].pav << left << setw(20) << setprecision(3) << galutinis << endl;
    }
    cout << "--------------------------------------------\n";
    cout << endl;
}

void MedianaVidurkis(stud& grupe) {
    sort(grupe.rez_nd.begin(), grupe.rez_nd.end());
    int m_size = grupe.rez_nd.size();
    if (m_size % 2 != 0)
        grupe.med = grupe.rez_nd[m_size / 2];
    else
        grupe.med = (grupe.rez_nd[m_size / 2 - 1] + grupe.rez_nd[m_size / 2]) / 2.0;

    double sum = 0;
    for (double pazym : grupe.rez_nd) {
        sum += pazym;
    }
    grupe.vid = sum / m_size;
}
void pasirinkimas4(vector<stud>& grupe) {
    system("dir *.txt");
    string filename;
    cin >> filename;
    ifstream file(filename); // Open the file
    if (!file) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string line;
    int word_count = 0; // Count of words in the first line
    // Read the first line to count the number of words
    getline(file, line);
    istringstream iss_first(line);
    while (iss_first >> line) {
        word_count++;
    }

    int expected_size = word_count - 3; // Deducting 2 for name and surname
    // Read data for each student from the file
    while (getline(file, line)) {
        istringstream iss(line);
        stud student;
        iss >> student.vard >> student.pav;

        // Resize rez_nd based on the expected size
        student.rez_nd.resize(expected_size);

        // Read rez_nd values
        for (int j = 0; j < expected_size; ++j) {
            if (iss.eof()) {
                // If there are fewer values than expected, adjust the size
                student.rez_nd.resize(j);
                break;
            }
            iss >> student.rez_nd[j];
        }

        iss >> student.rez_egz;
        MedianaVidurkis(student);
        grupe.push_back(student);
    }

    file.close();
    //printrez i faila*************
    ofstream fr("rezultatai.txt");
    char vid_med;
    double a = -1;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do{
    cin >> vid_med;
    }while(vid_med!='v'&&vid_med!='m');
    fr << "Vardas              Pavarde             "; if (vid_med == 'v') fr <<"Galutinis (Vid.)"<< endl;
                                            else if (vid_med == 'm') fr <<"Galutinis (Med.)"<< endl;
    fr << "--------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        if (vid_med == 'v') a = grupe[i].vid;
        else if (vid_med == 'm') a = grupe[i].med;
        double galutinis = (0.4 * a) + (0.6 * grupe[i].rez_egz);
        fr << left << setw(20) << grupe[i].vard << left << setw(20) << grupe[i].pav << left << setw(20) << setprecision(3) << galutinis << endl;
    }
    fr << "--------------------------------------------------------\n";
    fr.close();
    //**********
}

