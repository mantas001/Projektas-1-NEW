#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
using namespace std;
const int M = 15; // namu darbu uzduociu kiekis kai generuojama atsitiktinai

void pasirinkimas1(deque<stud>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        grupe.resize(n);
        for (int i = 0; i < n; ++i) {
            cout << "Studento vardas ir pavarde: ";
            cin >> grupe[i].vard >> grupe[i].pav;
            cout << "Studento egzamino rezultatas (1-10): ";
            cin >> grupe[i].rez_egz;
            if (cin.fail() || grupe[i].rez_egz < 1 || grupe[i].rez_egz > 10) {
                throw runtime_error("Netinkamas egzamino rezultatas.");
            }
            cout << "Namu darbu kiekis: ";
            int m;
            cin >> m;
            if (cin.fail() || m <= 0) {
                throw runtime_error("Netinkamas namu darbu kiekis.");
            }
            grupe[i].rez_nd.resize(m);
            for (int j = 0; j < m; ++j) {
                cout << j + 1 << "-os uzduoties rezultatas (1-10): ";
                cin >> grupe[i].rez_nd[j];
                if (cin.fail() || grupe[i].rez_nd[j] < 1 || grupe[i].rez_nd[j] > 10) {
                    throw runtime_error("Netinkamas namu darbo rezultatas.");
                }
            }
            MedianaVidurkis(grupe[i]);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
void pasirinkimas2(deque<stud>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
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
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void pasirinkimas3(deque<stud>& grupe) {
    try{
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        grupe.resize(n);
        for (int i = 0; i < n; ++i) {
            grupe[i].vard = "Vardas" + to_string(1 + rand() % 10);
            grupe[i].pav = "Pavarde" + to_string(1 + rand() % 10);
            grupe[i].rez_egz = 1 + rand() % 10;
            int m = 1 + rand() % M;
            grupe[i].rez_nd.resize(m);
            for (int j = 0; j < m; ++j) {
                grupe[i].rez_nd[j] = 1 + rand() % 10;
            }
            MedianaVidurkis(grupe[i]);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void printrez(deque<stud>& grupe) {
    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do{
    cin >> vid_med;
    if (vid_med!="v"&&vid_med!="m") cout << "Netinkama ivestis(irasykite 'v' arba 'm'): ";
    }while(vid_med!="v"&&vid_med!="m");

    //galutinis***************
    double a = -1;
    for (int i = 0; i < grupe.size(); i++) {
        if (vid_med == "v") a = grupe[i].vid;
        else if (vid_med == "m") a = grupe[i].med;
        double galutinis = (0.4 * a) + (0.6 * grupe[i].rez_egz);
        grupe[i].galut_iv=galutinis;
    }

    //rikiavimas
    sorting(grupe);
    //**********

    cout << "Vardas              Pavarde             "; if (vid_med == "v") cout <<"Galutinis (Vid.)"<< endl;
                                            else if (vid_med == "m") cout <<"Galutinis (Med.)"<< endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        cout << left << setw(20) << grupe[i].vard << left << setw(20) << grupe[i].pav << left << setw(20) << setprecision(3) << grupe[i].galut_iv << endl;
    }
    cout << "--------------------------------------------------------\n";
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
void pasirinkimas4(deque<stud>& grupe) {
    system("dir *.txt");
    string filename;
    cout << "Irasykite duomenu failo pavadinima: ";
    cin >> filename;
    try {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Nepavyko atidaryti failo.");

    }

    string line;
    int word_count = 0;

    getline(file, line);
    istringstream iss_first(line);
    while (iss_first >> line) {
        word_count++;
    }

    int expected_size = word_count - 3;

    auto start = std::chrono::high_resolution_clock::now();
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
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
    ofstream fr("rezultatai.txt");
    fr <<"Nuskaityti duomenis uztruko: "<< diff.count() << " s\n";
    file.close();

    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do{
    cin >> vid_med;
    if (vid_med!="v"&&vid_med!="m") cout << "Netinkama ivestis(irasykite 'v' arba 'm'): ";
    }while(vid_med!="v"&&vid_med!="m");

    //galutinis***************
    double a = -1;
    for (int i = 0; i < grupe.size(); i++) {
        if (vid_med == "v") a = grupe[i].vid;
        else if (vid_med == "m") a = grupe[i].med;
        double galutinis = (0.4 * a) + (0.6 * grupe[i].rez_egz);
        grupe[i].galut_iv=galutinis;
    }
    //************************

    //rikiavimas
    sorting(grupe);
    //**********

    //printrez i faila*************
    
    fr << "Vardas              Pavarde             "; if (vid_med == "v") fr <<"Galutinis (Vid.)"<< endl;
                                            else if (vid_med == "m") fr <<"Galutinis (Med.)"<< endl;
    fr << "--------------------------------------------------------" << endl;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < grupe.size(); i++) {
        fr << left << setw(20) << grupe[i].vard << left << setw(20) << grupe[i].pav << left << setw(20) << setprecision(3) << grupe[i].galut_iv << endl;
    }
    diff = std::chrono::high_resolution_clock::now()-start;
    fr << "--------------------------------------------------------\n";
    fr <<"Irasyti duomenis uztruko: "<< diff.count() << " s\n";
    fr.close();
    //**********
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
}
void sorting(deque<stud>& grupe){
    string sort_choice, sort_order;
    cout << "Rikiuoti pagal (v - vardas, p - pavarde, g - galutinis ivertinimas): ";
    do{
    cin >> sort_choice;
    if (sort_choice!="v"&&sort_choice!="p"&&sort_choice!="g") cout << "Netinkama ivestis(irasykite 'v' , 'p' arba 'g'): ";
    }while(sort_choice!="v"&&sort_choice!="p"&&sort_choice!="g");

    cout << "Pasirinkite rikiavimo tvarka (d - didejimo, m - mazejimo): ";
    do{
    cin >> sort_order;
    if (sort_order!="d"&&sort_order!="m") cout << "Netinkama ivestis(irasykite 'd' arba 'm'): ";
    }while(sort_order!="d"&&sort_order!="m");

    switch (sort_choice[0]) {
        case 'v':
            if (sort_order == "d") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.vard < b.vard;
                });
            } else if (sort_order == "m") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.vard > b.vard;
                });
            }
            break;
        case 'p':
            if (sort_order == "d") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.pav < b.pav;
                });
            } else if (sort_order == "m") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.pav > b.pav;
                });
            }
            break;
        case 'g':
            if (sort_order == "d") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.galut_iv < b.galut_iv;
                });
            } else if (sort_order == "m") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.galut_iv > b.galut_iv;
                });
            }
            break;
        default:
            cout << "Neteisingas pasirinkimas" << endl;
            return;
    }
}
void duomenu_sukurimas(std::deque<stud>& grupe, std::chrono::duration<double>& duom_create_diff, int& duom){
    //int duom;
    cout << "Kiek eiluciu duomenu generuoti? ";
    cin >> duom;
    string filename2="duomenys" + to_string(duom) + ".txt";
    auto duom_create_start = std::chrono::high_resolution_clock::now();
    ofstream fr(filename2);
    fr << "Vardas              Pavarde             ND1       ND2       ND3       ND4       ND5       ND6       ND7       ND8       ND9       ND10      ND11      ND12      ND13      ND14      ND15      Egz." << endl;
    for (int i=0; i<duom; i++){
        fr << left << setw(20) << "Vardas" + to_string(i+1) << left << setw(20) << "Pavarde" + to_string(i+1);
        for (int j=0; j<15; j++){
            fr << left << setw(10) << 1 + rand() % 10;
        }
        fr << 1 + rand() % 10;
        fr << endl;
    }
    fr.close();
    duom_create_diff = std::chrono::high_resolution_clock::now()-duom_create_start;
}

void pasirinkimas6(std::deque<stud>& grupe, string& filename2, int& duom, std::chrono::duration<double>& duom_create_diff) {
    system("dir *.txt");
    string filename;
    cout << "Irasykite duomenu failo pavadinima: ";
    cin >> filename;

    deque<stud> saunuoliai;
    deque<stud> vargsai;

    stringstream my_buffer;
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file.\n";
        return;
    }

    my_buffer << file.rdbuf();
    file.close();

    deque<string> splited;
    string line;

    while (getline(my_buffer, line)) {
        splited.push_back(line);
    }

    int eilutes = 0;
    auto duom_read_start = std::chrono::high_resolution_clock::now();
    for (const string& line : splited) {
        istringstream iss(line);
        stud student;

        if (!(iss >> student.vard >> student.pav)) {
            cerr << "Error reading student's name and surname.\n";
            continue;
        }

        int grade;
        while (iss >> grade) {
            student.rez_nd.push_back(grade);
        }


        if (student.rez_nd.empty()) {
            cerr << "";
            continue;
        }

        student.rez_egz = student.rez_nd.back();

        std::chrono::high_resolution_clock::time_point end_reading = std::chrono::high_resolution_clock::now();

        eilutes++;

        MedianaVidurkis(student);

        grupe.push_back(std::move(student));
    }

    std::chrono::duration<double> duom_read_diff = std::chrono::high_resolution_clock::now() - duom_read_start;

    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do {
        cin >> vid_med;
        if (vid_med != "v" && vid_med != "m") cout << "Netinkama ivestis(irasykite 'v' arba 'm'): ";
    } while (vid_med != "v" && vid_med != "m");

    //galutinis***************
    double a = -1;
    for (int i = 0; i < grupe.size(); i++) {
        if (vid_med == "v") a = grupe[i].vid;
        else if (vid_med == "m") a = grupe[i].med;
        double galutinis = (0.4 * a) + (0.6 * grupe[i].rez_egz);
        grupe[i].galut_iv = galutinis;
    }
    //************************
    auto duom_sort_start = std::chrono::high_resolution_clock::now();
    saunuoliai_vargsai(grupe, vargsai);
    std::chrono::duration<double> duom_sort_diff = std::chrono::high_resolution_clock::now() - duom_sort_start;

    cout << "Rusiuojami saunuoliai" << endl;
    sorting(grupe);
    cout << "Rusiuojami vargsai" << endl;
    sorting(vargsai);

    string ofstreamfile = "saunuoliai" + to_string(eilutes) + ".txt";
    ofstream saunuoliai_file(ofstreamfile);
    auto duom_write_start = std::chrono::high_resolution_clock::now();
    for (const auto& student : grupe) {
        saunuoliai_file << left << setw(20) << student.vard << setw(20) << student.pav << setw(10) << fixed << setprecision(2) << student.galut_iv << endl;
    }
    saunuoliai_file.close();

    string ofstreamfile2 = "vargsai" + to_string(eilutes) + ".txt";
    ofstream vargsai_file(ofstreamfile2);
    for (const auto& student : vargsai) {
        vargsai_file << left << setw(20) << student.vard << setw(20) << student.pav << setw(10) << fixed << setprecision(2) << student.galut_iv << endl;
    }
    vargsai_file.close();

    std::chrono::duration<double> duom_write_diff = std::chrono::high_resolution_clock::now() - duom_write_start;

    grupe.clear();
    vargsai.clear();
    saunuoliai.clear();

    cout << "***********************************************************" << endl;
    cout << "Nuskaityti " << eilutes << " irasu uztruko: " << duom_read_diff.count() << " s\n";
    cout << "Surikiuoti " << eilutes << " irasu uztruko: " << duom_sort_diff.count() << " s\n";
    cout << "Irasyti " << eilutes << " irasu uztruko: " << duom_write_diff.count() << " s\n";
    cout << "***********************************************************" << endl;
    cout << endl;
}
void saunuoliai_vargsai(std::deque<stud>& grupe, std::deque<stud>& vargsai) {
    // Partition the grupe vector based on below_5 condition
    auto partition_point = std::partition(grupe.begin(), grupe.end(), below_5);

    // Move the partitioned elements to vargsai
    std::move(partition_point, grupe.end(), std::back_inserter(vargsai));

    // Erase the partitioned elements from grupe
    grupe.erase(partition_point, grupe.end());
}
bool below_5(const stud& student) {
    return student.galut_iv < 5;
}

