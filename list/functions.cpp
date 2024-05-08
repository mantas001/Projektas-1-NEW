#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int M = 15; // namu darbu uzduociu kiekis kai generuojama atsitiktinai

void pasirinkimas1(list<stud>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        for (int i = 0; i < n; ++i) {
            stud student;
            cout << "Studento vardas ir pavarde: ";
            cin >> student.vard >> student.pav;
            cout << "Studento egzamino rezultatas (1-10): ";
            cin >> student.rez_egz;
            if (cin.fail() || student.rez_egz < 1 || student.rez_egz > 10) {
                throw runtime_error("Netinkamas egzamino rezultatas.");
            }
            cout << "Namu darbu kiekis: ";
            int m;
            cin >> m;
            if (cin.fail() || m <= 0) {
                throw runtime_error("Netinkamas namu darbu kiekis.");
            }
            for (int j = 0; j < m; ++j) {
                double nd;
                cout << j + 1 << "-os uzduoties rezultatas (1-10): ";
                cin >> nd;
                if (cin.fail() || nd < 1 || nd > 10) {
                    throw runtime_error("Netinkamas namu darbo rezultatas.");
                }
                student.rez_nd.push_back(nd);
            }
            MedianaVidurkis(student);
            grupe.push_back(student);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}

void pasirinkimas2(list<stud>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        for (int i = 0; i < n; ++i) {
            stud student;
            cout << "studento vardas ir pavarde: ";
            cin >> student.vard >> student.pav;
            student.rez_egz = 1 + rand() % 10;;
            int m = 1 + rand() % M;
            for (int j = 0; j < m; ++j) {
                student.rez_nd.push_back(1 + rand() % 10);
            }
            MedianaVidurkis(student);
            grupe.push_back(student);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void pasirinkimas3(list<stud>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        for (int i = 0; i < n; ++i) {
            stud student;
            student.vard = "Vardas" + to_string(1 + rand() % 10);
            student.pav = "Pavarde" + to_string(1 + rand() % 10);
            student.rez_egz = 1 + rand() % 10;
            int m = 1 + rand() % M;
            for (int j = 0; j < m; ++j) {
                student.rez_nd.push_back(1 + rand() % 10);
            }
            MedianaVidurkis(student);
            grupe.push_back(student);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void printrez(list<stud>& grupe) {
    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do {
        cin >> vid_med;
        if (vid_med != "v" && vid_med != "m") cout << "Netinkama ivestis(irasykite 'v' arba 'm'): ";
    } while (vid_med != "v" && vid_med != "m");

    // Calculate final grade for each student
    for (auto& student : grupe) {
        double a = (vid_med == "v") ? student.vid : student.med;
        double galutinis = (0.4 * a) + (0.6 * student.rez_egz);
        student.galut_iv = galutinis;
    }

    sorting(grupe);

    cout << "Vardas              Pavarde             ";
    if (vid_med == "v")
        cout << "Galutinis (Vid.)" << endl;
    else if (vid_med == "m")
        cout << "Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (const auto& student : grupe) {
        cout << left << setw(20) << student.vard << left << setw(20) << student.pav << left << setw(20) << setprecision(3) << student.galut_iv << endl;
    }
    cout << "--------------------------------------------------------\n";
    cout << endl;
}

void MedianaVidurkis(stud& student) {
    student.rez_nd.sort();
    int m_size = student.rez_nd.size();
    auto it = student.rez_nd.begin();
    for (int i = 0; i < m_size / 2; ++i) {
        ++it;
    }
    if (m_size % 2 != 0)
        student.med = *it;
    else
        student.med = (*it + *(--it)) / 2.0;

        double sum = 0;
    for (auto& nd : student.rez_nd) {
        sum += nd;
    }
    student.vid = sum / m_size;
}

void pasirinkimas4(list<stud>& grupe) {
    string filename;
    cout << "Iveskite failo pavadinima: ";
    cin >> filename;
    ifstream infile(filename);
    if (!infile) {
        cerr << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        stud student;
        ss >> student.vard >> student.pav;
        double grade;
        while (ss >> grade) {
            student.rez_nd.push_back(grade);
        }
        if (!student.rez_nd.empty()) {
            student.rez_egz = student.rez_nd.back();
            student.rez_nd.pop_back();
        }
        MedianaVidurkis(student);
        grupe.push_back(student);
    }

    printrez(grupe);
}

void sorting(std::list<stud>& grupe) {
    std::string sort_choice, sort_order;
    std::cout << "Rikiuoti pagal (v - vardas, p - pavarde, g - galutinis ivertinimas): ";
    do {
        std::cin >> sort_choice;
        if (sort_choice != "v" && sort_choice != "p" && sort_choice != "g") {
            std::cout << "Netinkama ivestis(irasykite 'v' , 'p' arba 'g'): ";
        }
    } while (sort_choice != "v" && sort_choice != "p" && sort_choice != "g");

    std::cout << "Pasirinkite rikiavimo tvarka (d - didejimo, m - mazejimo): ";
    do {
        std::cin >> sort_order;
        if (sort_order != "d" && sort_order != "m") {
            std::cout << "Netinkama ivestis(irasykite 'd' arba 'm'): ";
        }
    } while (sort_order != "d" && sort_order != "m");

    switch (sort_choice[0]) {
        case 'v':
            if (sort_order == "d") {
                grupe.sort([](const stud& a, const stud& b) {
                    return a.vard < b.vard;
                });
            } else if (sort_order == "m") {
                grupe.sort([](const stud& a, const stud& b) {
                    return a.vard > b.vard;
                });
            }
            break;
        case 'p':
            if (sort_order == "d") {
                grupe.sort([](const stud& a, const stud& b) {
                    return a.pav < b.pav;
                });
            } else if (sort_order == "m") {
                grupe.sort([](const stud& a, const stud& b) {
                    return a.pav > b.pav;
                });
            }
            break;
        case 'g':
            if (sort_order == "d") {
                grupe.sort([](const stud& a, const stud& b) {
                    return a.galut_iv < b.galut_iv;
                });
            } else if (sort_order == "m") {
                grupe.sort([](const stud& a, const stud& b) {
                    return a.galut_iv > b.galut_iv;
                });
            }
            break;
        default:
            std::cout << "Neteisingas pasirinkimas" << std::endl;
            return;
    }
}
void duomenu_sukurimas(list<stud>& grupe, chrono::duration<double>& duom_create_diff, int& duom) {
    try {
        auto start = chrono::steady_clock::now();

        for (int i = 0; i < duom; ++i) {
            stud student;
            student.vard = "Vardas" + to_string(1 + rand() % 10);
            student.pav = "Pavarde" + to_string(1 + rand() % 10);
            student.rez_egz = 1 + rand() % 10;
            int m = 1 + rand() % M;
            for (int j = 0; j < m; ++j) {
                student.rez_nd.push_back(1 + rand() % 10);
            }
            MedianaVidurkis(student);
            grupe.push_back(student);
        }

        auto end = chrono::steady_clock::now();
        duom_create_diff = end - start;

        cout << "Nauji duomenys sukurti." << endl;
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
}

void pasirinkimas6(std::list<stud>& grupe, std::string& filename2, int& duom, std::chrono::duration<double>& duom_create_diff){

    system("dir *.txt");
    string filename;
    cout << "Irasykite duomenu failo pavadinima: ";
    cin >> filename;

    //list<stud> saunuoliai;
    list<stud> vargsai;

    stringstream my_buffer;
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file.\n";
        return;
    }

    my_buffer << file.rdbuf();
    file.close();

    list<string> splited;
    string line;

    while (getline(my_buffer, line)) {
        splited.push_back(line);
    }

    int eilutes = 0;
    int word_count = 0;
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
    do{
    cin >> vid_med;
    if (vid_med!="v"&&vid_med!="m") cout << "Netinkama ivestis(irasykite 'v' arba 'm'): ";
    }while(vid_med!="v"&&vid_med!="m");

    //galutinis***************
    double a = -1;
    for (auto it = grupe.begin(); it != grupe.end(); ++it) {
    if (vid_med == "v") a = it->vid;
    else if (vid_med == "m") a = it->med;
    double galutinis = (0.4 * a) + (0.6 * it->rez_egz);
    it->galut_iv = galutinis;
    }

    //************************
    auto duom_sort_start = std::chrono::high_resolution_clock::now();
    saunuoliai_vargsai(grupe, vargsai);
    std::chrono::duration<double> duom_sort_diff = std::chrono::high_resolution_clock::now()-duom_sort_start;

    cout << "Rusiuojami saunuoliai"<< endl;
    sorting(grupe);
    cout << "Rusiuojami vargsai"<< endl;
    sorting(vargsai);

    string ofstreamfile="saunuoliai" + to_string(eilutes) + ".txt";
    ofstream saunuoliai_file(ofstreamfile);
    auto duom_write_start = std::chrono::high_resolution_clock::now();
    for (const auto& student : grupe) {
        saunuoliai_file << left << setw(20) << student.vard << setw(20) << student.pav << setw(10) << fixed << setprecision(2) << student.galut_iv << endl;
    }
    saunuoliai_file.close();


    string ofstreamfile2="vargsai" + to_string(eilutes) + ".txt";
    ofstream vargsai_file(ofstreamfile2);
    for (const auto& student : vargsai) {
        vargsai_file << left << setw(20) << student.vard << setw(20) << student.pav << setw(10) << fixed << setprecision(2) << student.galut_iv << endl;
    }
    vargsai_file.close();
    std::chrono::duration<double> duom_write_diff = std::chrono::high_resolution_clock::now()-duom_write_start;

    grupe.clear();
    vargsai.clear();
    //saunuoliai.clear();

    cout <<"***********************************************************"<<endl;
    cout <<"Nuskaityti "<< eilutes << " irasu uztruko: "<< duom_read_diff.count() << " s\n";
    cout <<"Surikiuoti "<< eilutes << " irasu uztruko: "<< duom_sort_diff.count() << " s\n";
    cout <<"Irasyti "<< eilutes << " irasu uztruko: "<< duom_write_diff.count() << " s\n";
    cout <<"***********************************************************"<<endl; 
    cout << endl;
}
void saunuoliai_vargsai(std::list<stud>& grupe, std::list<stud>& vargsai) {
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