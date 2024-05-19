#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
using namespace std;
const int M = 15; // namu darbu uzduociu kiekis kai generuojama atsitiktinai

    Student_class::Student_class(){
        vard_ = " ";
        pav_ = " ";
        rez_nd_.resize(0);
        rez_egz_= {};
        vid_= {};
        med_= {};
        galut_iv_= {};
    };
    Student_class::Student_class(std::string vard, std::string pav, std::vector<double> rez_nd, double rez_egz, double vid, double med, double galut_iv){
        vard_ = vard;
        pav_ = pav;
        rez_nd_ = rez_nd;
        rez_egz_= rez_egz;
        vid_= vid;
        med_= med;
        galut_iv_= galut_iv;
    };
    
    Student_class::~Student_class(){
        vard_ = " ";
        pav_ = " ";
        rez_nd_.clear();
        rez_egz_ = 0.0;
        vid_ = 0.0;
        med_ = 0.0;
        galut_iv_ = 0.0;
    };


void Student_class::pasirinkimas1(std::vector<Student_class>& grupe) {
    
    try {
        Student_class student;
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        
        // Resize the vector to accommodate 'n' students
        grupe.resize(n);
        string vardas, pavarde;
        for (int i = 0; i < n; ++i) {
            
            cout << "Studento vardas ir pavarde: ";
            cin >> vardas >> pavarde;
            
            // Set the student's name using setter functions
            grupe[i].setVard(vardas);
            grupe[i].setPav(pavarde);
            
            cout << "Studento egzamino rezultatas (1-10): ";
            double rez_egz_temp;
            cin >> rez_egz_temp;
            if (cin.fail() || rez_egz_temp < 1 || rez_egz_temp > 10) {
                throw runtime_error("Netinkamas egzamino rezultatas.");
            }
            
            // Set the exam result using setter function
            grupe[i].setRezEgz(rez_egz_temp);
            
            cout << "Namu darbu kiekis: ";
            int m=0;
            cin >> m;
            if (cin.fail() || m <= 0) {
                throw runtime_error("Netinkamas namu darbu kiekis.");
            }
            
            // Resize the vector to accommodate 'm' homework results and initialize elements to zero
            grupe[i].getRezNd().resize(m, 0.0);


            cout << "Size of rez_nd_ vector after resizing: " << grupe[i].getRezNd().size() << endl;

            for (int j = 0; j < m; ++j) {
                cout << j + 1 << "-os uzduoties rezultatas (1-10): ";
                double rez_nd_temp;
                cin >> rez_nd_temp;
                if (cin.fail() || rez_nd_temp < 1 || rez_nd_temp > 10) {
                    throw runtime_error("Netinkamas namu darbo rezultatas.");
                }

                // Add the homework result using the method
                grupe[i].addGradeToRezNd(rez_nd_temp);
            }

            // Print out size and values of rez_nd_ vector
            cout << "Size of rez_nd_ vector after adding grades: " << grupe[i].getRezNd().size() << endl;
            for (double grade : grupe[i].getRezNd()) {
                cout << grade << " ";
            }
            cout << endl;


            
            // Calculate median and average for each student
            MedianaVidurkis(grupe[i]); // <<<<<<---------------------------sitaip, o ne sitaip student.MedianaVidurkis(student);
        
        }

        
            // Print results for all students
            printrez(grupe);

        
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}


void Student_class::pasirinkimas2(std::vector<Student_class>& grupe) {
    
    try {
        Student_class student;
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        grupe.resize(n);
        for (int i = 0; i < n; ++i) {
            cout << "studento vardas ir pavarde: ";
            string vardas, pavarde;
            cin >> vardas;
            grupe[i].setVard(vardas);
            cin >> pavarde;
            grupe[i].setPav(pavarde);
            grupe[i].setRezEgz(1 + rand() % 10);
            int m = 1 + rand() % M;
            grupe[i].getRezNd().resize(m, 0.0);

            for (int j = 0; j < m; ++j) {
                grupe[i].addGradeToRezNd(1 + rand() % 10);
            }
            MedianaVidurkis(grupe[i]);

        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}


void Student_class::pasirinkimas3(std::vector<Student_class>& grupe) {
    
    try{
        Student_class student;
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        grupe.resize(n);
        for (int i = 0; i < n; ++i) {
            grupe[i].setVard("Vardas" + to_string(1 + rand() % 10));
            grupe[i].setPav("Pavarde" + to_string(1 + rand() % 10));
            grupe[i].setRezEgz(1 + rand() % 10);
            int m = 1 + rand() % M;
            grupe[i].getRezNd().resize(m, 0.0);
            for (int j = 0; j < m; ++j) {
                grupe[i].addGradeToRezNd(1 + rand() % 10);
            }
            MedianaVidurkis(grupe[i]);

        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}

void Student_class::printrez(std::vector<Student_class>& grupe) {
    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do {
        cin >> vid_med;
        if (vid_med != "v" && vid_med != "m") {
            cout << "Netinkama ivestis (irasykite 'v' arba 'm'): ";
        }
    } while (vid_med != "v" && vid_med != "m");

    // Calculate final grades
    for (int i = 0; i < grupe.size(); i++) {
        double a = (vid_med == "v") ? grupe[i].getVid() : grupe[i].getMed();
        double galutinis = (0.4 * a) + (0.6 * grupe[i].getRezEgz());
        grupe[i].setGalutIv(galutinis);
    }

    sorting(grupe);

    cout << "Vardas              Pavarde             "; 
    if (vid_med == "v") 
        cout << "Galutinis (Vid.)" << endl;
    else if (vid_med == "m") 
        cout << "Galutinis (Med.)" << endl;

    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        cout << left << setw(20) << grupe[i].getVard() << left << setw(20) << grupe[i].getPav() 
             << left << setw(20) << setprecision(3) << grupe[i].getGalutIv() << endl;
    }
    cout << "--------------------------------------------------------\n";
    cout << endl;
}

void Student_class::MedianaVidurkis(Student_class& grupe) {
    // Access and modify vid and med using the getter and setter methods
    const std::vector<double>& rez_nd_temp = grupe.getRezNd();

    // Make a copy of rez_nd and sort it
    std::vector<double> sorted_rez_nd = rez_nd_temp;
    std::sort(sorted_rez_nd.begin(), sorted_rez_nd.end());
    
    int m_size = sorted_rez_nd.size();
    
    //mediana
    if (m_size % 2 != 0)
        grupe.setMed(sorted_rez_nd[m_size / 2]);
    else
        grupe.setMed((sorted_rez_nd[m_size / 2 - 1] + sorted_rez_nd[m_size / 2]) / 2.0);

    //vidurkis
    double sum = 0;
    for (int i = 0; i < m_size; ++i) {
        sum += sorted_rez_nd[i];
    }
    grupe.setVid(sum/m_size);
}

void Student_class::pasirinkimas4(std::vector<Student_class>& grupe) {
    system("dir *.txt");
    string filename;
    cout << "Irasykite duomenu failo pavadinima (kuriame yra vardas, pavarde, n namu darbu kiekis ir egzamino rezultatas): ";
    cin >> filename;
    try {
        ifstream file(filename); // Open the file
        if (!file) {
            throw runtime_error("Nepavyko atidaryti failo.");
        }

        string line;
        int word_count = 0; // Count of words in the first line
        // Read the first line to count the number of words
        getline(file, line);
        istringstream iss_first(line);
        while (iss_first >> line) {
            word_count++;
        }

        int expected_size = word_count - 3; // Deducting 3 for name and surname and rez_egz
        // Read data for each student from the file
        auto start = std::chrono::high_resolution_clock::now();
        int eilutes=0;
        while (getline(file, line)) {
            
            eilutes++;
            Student_class student; // Create a new student object
            std::string vardas, pavarde;
            istringstream iss(line);
            iss >> vardas >> pavarde;
            student.setVard(vardas);
            student.setPav(pavarde);

            // Resize rez_nd based on the expected size
            student.getRezNd().resize(expected_size, 0.0);

            // Read rez_nd values
            for (int j = 0; j < expected_size; ++j) {
                double rez_nd_temp;
                if (!(iss >> rez_nd_temp)) {
                    // Handle the case where there are fewer values than expected
                    student.getRezNd().resize(j);
                    break;
                }
                student.addGradeToRezNd(rez_nd_temp);
            }

            double rez_egz_temp;
            if (!(iss >> rez_egz_temp)) {
                throw runtime_error("Nepavyko nuskaityti egzamino rezultato.");
            }
            student.setRezEgz(rez_egz_temp);
            
            student.MedianaVidurkis(student);
            grupe.push_back(student); // Add the student to the vector
        }




        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
        string pav_temp = "rezultatai" + to_string(eilutes) + ".txt";
        ofstream fr(pav_temp);
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
            if (vid_med == "v") a = grupe[i].getVid();
            else if (vid_med == "m") a = grupe[i].getMed();
            double galutinis = (0.4 * a) + (0.6 * grupe[i].getRezEgz());
            grupe[i].setGalutIv(galutinis);
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
            fr << left << setw(20) << grupe[i].getVard() << left << setw(20) << grupe[i].getPav() << left << setw(20) << setprecision(3) << grupe[i].getGalutIv() << endl;
        }
        diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
        fr << "--------------------------------------------------------\n";
        fr <<"Irasyti duomenis uztruko: "<< diff.count() << " s\n";
        fr.close();
        //**********
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
    grupe.clear();
}

void Student_class::sorting(std::vector<Student_class>& grupe){
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
    case 'v': // Assuming 'v' represents sorting by name
        if (sort_order == "d") {
            sort(grupe.begin(), grupe.end(), [](const Student_class& a, const Student_class& b) {
                return (a.getVard() < b.getVard());
            });
        } else if (sort_order == "m") {
            sort(grupe.begin(), grupe.end(), [](const Student_class& a, const Student_class& b) {
                return (a.getVard() > b.getVard());
            });
        }
        break;
    case 'p': // Assuming 'p' represents sorting by name
        if (sort_order == "d") {
            sort(grupe.begin(), grupe.end(), [](const Student_class& a, const Student_class& b) {
                return (a.getPav() < b.getPav());
            });
        } else if (sort_order == "m") {
            sort(grupe.begin(), grupe.end(), [](const Student_class& a, const Student_class& b) {
                return (a.getPav() > b.getPav());
            });
        }
        break;
    case 'g': // Assuming 'g' represents sorting by grade
        if (sort_order == "d") {
            sort(grupe.begin(), grupe.end(), [](const Student_class& a, const Student_class& b) {
                return (a.getGalutIv() < b.getGalutIv());
            });
        } else if (sort_order == "m") {
            sort(grupe.begin(), grupe.end(), [](const Student_class& a, const Student_class& b) {
                return (a.getGalutIv() > b.getGalutIv());
            });
        }
        break;
    default:
            cout << "Neteisingas pasirinkimas" << endl;
            return;
    }
}
void Student_class::pasirinkimas6(std::vector<Student_class>& grupe, std::string& filename2, int& duom, std::chrono::duration<double>& duom_create_diff) {
    system("dir *.txt");
    string filename;
    cout << "Irasykite duomenu failo pavadinima (kuriame yra vardas, pavarde ir galutinis ivertinimas): ";
    cin >> filename;

    //vector<stud> saunuoliai;
    vector<Student_class> vargsai;

    stringstream my_buffer;
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file.\n";
        return;
    }

    // Read the file into a buffer
    my_buffer << file.rdbuf();
    file.close();

    vector<string> splited;
    string line;

    while (getline(my_buffer, line)) {
        splited.push_back(line);
    }

    int eilutes = 0;
    auto duom_read_start = std::chrono::high_resolution_clock::now();
    for (const string& line : splited) {
        istringstream iss(line);
        Student_class student;

        string vardas, pavarde; // Temporary variables for name and surname

        if (!(iss >> vardas >> pavarde)) {
            cerr << "Error reading student's name and surname.\n";
            continue;
        }

        // Set the name and surname using setter functions
        student.setVard(vardas);
        student.setPav(pavarde);

        double grade;
        while (iss >> grade) {
            student.addGradeToRezNd(grade);
        }

        // To retrieve the rez_nd vector
        std::vector<double> grades = student.getRezNd();

        if (student.isRezNdEmpty()) {
            cerr << "Error: No grades found for student.\n";
            continue;
        }

        student.setRezEgzFromRezNd();

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

    // Calculate final grades
    double a = -1;
    for (int i = 0; i < grupe.size(); i++) {
        double a = (vid_med == "v") ? grupe[i].getVid() : grupe[i].getMed();
        double galutinis = (0.4 * a) + (0.6 * grupe[i].getRezEgz());
        grupe[i].setGalutIv(galutinis);
    }

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
    for (const auto& student : vargsai) {
        saunuoliai_file << left << setw(20) << student.getVard() << setw(20) << student.getPav() << setw(10) << fixed << setprecision(2) << student.getGalutIv() << endl;
    }

    saunuoliai_file.close();

    string ofstreamfile2 = "vargsai" + to_string(eilutes) + ".txt";
    ofstream vargsai_file(ofstreamfile2);
    for (const auto& student : grupe) {
        vargsai_file << left << setw(20) << student.getVard() << setw(20) << student.getPav() << setw(10) << fixed << setprecision(2) << student.getGalutIv() << endl;
    }

    vargsai_file.close();

    std::chrono::duration<double> duom_write_diff = std::chrono::high_resolution_clock::now() - duom_write_start;

    grupe.clear();
    vargsai.clear();

    cout << "***********************************************************" << endl;
    cout << "Nuskaityti " << eilutes << " irasu uztruko: " << duom_read_diff.count() << " s\n";
    cout << "Surikiuoti " << eilutes << " irasu uztruko: " << duom_sort_diff.count() << " s\n";
    cout << "Irasyti " << eilutes << " irasu uztruko: " << duom_write_diff.count() << " s\n";
    cout << "***********************************************************" << endl;
    cout << endl;
}

void Student_class::duomenu_sukurimas(std::vector<Student_class>& grupe, std::chrono::duration<double>& duom_create_diff, int& duom){
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
void Student_class::saunuoliai_vargsai(std::vector<Student_class>& grupe, std::vector<Student_class>& vargsai) {
    // Partition the grupe vector based on below_5 condition using a lambda function
    auto partition_point = std::partition(grupe.begin(), grupe.end(), [](const Student_class& student) {
        return student.getGalutIv() < 5;
    });

    // Move the partitioned elements to vargsai
    std::move(partition_point, grupe.end(), std::back_inserter(vargsai));

    // Erase the partitioned elements from grupe
    grupe.erase(partition_point, grupe.end());
}
bool below_5(const Student_class& student) {
    return student.getGalutIv() < 5;
}