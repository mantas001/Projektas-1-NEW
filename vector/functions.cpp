#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
using namespace std;
const int M = 15; //namu darbu uzduociu kiekis kai generuojama atsitiktinai

    Student_class::Student_class() 
    : Zmogus("", ""), rez_nd_(), rez_egz_(0.0), vid_(0.0), med_(0.0), galut_iv_(0.0) {}

    Student_class::Student_class(string vard, string pav, vector<double> rez_nd, double rez_egz, double vid, double med, double galut_iv)
    : Zmogus(vard, pav), rez_nd_(rez_nd), rez_egz_(rez_egz), vid_(vid), med_(med), galut_iv_(galut_iv) {}

    Student_class::~Student_class() {
        cout << "destructor'ius veikia!!!" << endl << endl;//eilute testui
        clear();
    }

    Student_class::Student_class(const Student_class& other)
    : Zmogus(other), rez_nd_(other.rez_nd_), rez_egz_(other.rez_egz_), vid_(other.vid_), med_(other.med_), galut_iv_(other.galut_iv_) {}


    Student_class& Student_class::operator=(const Student_class& other) {
        if (this != &other) {
            Zmogus::operator=(other);
            rez_nd_ = other.rez_nd_;
            rez_egz_ = other.rez_egz_;
            vid_ = other.vid_;
            med_ = other.med_;
            galut_iv_ = other.galut_iv_;
        }
        return *this;
    }

    Student_class::Student_class(Student_class&& other) noexcept
    : Zmogus(move(other.vard_), move(other.pav_)), rez_nd_(move(other.rez_nd_)), rez_egz_(other.rez_egz_), vid_(other.vid_), med_(other.med_), galut_iv_(other.galut_iv_) {
    other.clear();
    }

    Student_class& Student_class::operator=(Student_class&& other) noexcept {
        if (this != &other) {
            Zmogus::operator=(move(other));
            rez_nd_ = move(other.rez_nd_);
            rez_egz_ = other.rez_egz_;
            vid_ = other.vid_;
            med_ = other.med_;
            galut_iv_ = other.galut_iv_;
            other.clear();
        }
        return *this;
    }

    istream& operator>>(istream& is, Student_class& student) {
        // Read data into the student object
        cout << "Studento vardas ir pavarde: ";
        is >> student.vard_ >> student.pav_;
        // You can add more input prompts and read more data here
        return is;
    }

    // Output operator
    ostream& operator<<(ostream& os, const Student_class& student) {
        // Print data from the student object
        os << "Studento vardas ir pavarde: " << student.vard_ << " " << student.pav_;
        // You can print more data here if needed
        return os;
    }

void Student_class::pasirinkimas1(std::vector<Student_class>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        //Resize vector to n students
        grupe.resize(n);
        for (int i = 0; i < n; ++i) {
            
            cin >> grupe[i];
            
            cout << "Studento egzamino rezultatas (1-10): ";
            double rez_egz_temp;
            cin >> rez_egz_temp;
            if (cin.fail() || rez_egz_temp < 1 || rez_egz_temp > 10) {
                throw runtime_error("Netinkamas egzamino rezultatas.");
            }
            
            //Set egz
            grupe[i].setRezEgz(rez_egz_temp);
            
            cout << "Namu darbu kiekis: ";
            int m=0;
            cin >> m;
            if (cin.fail() || m <= 0) {
                throw runtime_error("Netinkamas namu darbu kiekis.");
            }
            
            grupe[i].getRezNd().resize(m, 0.0);

            for (int j = 0; j < m; ++j) {
                cout << j + 1 << "-os uzduoties rezultatas (1-10): ";
                double rez_nd_temp;
                cin >> rez_nd_temp;
                if (cin.fail() || rez_nd_temp < 1 || rez_nd_temp > 10) {
                    throw runtime_error("Netinkamas namu darbo rezultatas.");
                }
                grupe[i].addGradeToRezNd(rez_nd_temp);
            }
            MedianaVidurkis(grupe[i]);
        }
        printrez(grupe);
        grupe.clear();
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); //Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore invalid input
    }
}

void Student_class::pasirinkimas2(vector<Student_class>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        grupe.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> grupe[i];
            grupe[i].setRezEgz(1 + rand() % 10);
            int m = 1 + rand() % M;
            grupe[i].getRezNd().resize(m, 0.0);

            for (int j = 0; j < m; ++j) {
                grupe[i].addGradeToRezNd(1 + rand() % 10);
            }
            MedianaVidurkis(grupe[i]);
        }
        printrez(grupe);
        grupe.clear();
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); //Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore invalid input
    }
}

void Student_class::pasirinkimas3(vector<Student_class>& grupe) {
    try{
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
        grupe.clear();
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); //Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore invalid input
    }
}

void Student_class::printrez(vector<Student_class>& grupe) {
    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do {
        cin >> vid_med;
        if (vid_med != "v" && vid_med != "m") {
            cout << "Netinkama ivestis (irasykite 'v' arba 'm'): ";
        }
    } while (vid_med != "v" && vid_med != "m");

    //Calculate final grades
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
    const vector<double>& rez_nd_temp = grupe.getRezNd();

    // Copy of rez_nd
    vector<double> sorted_rez_nd = rez_nd_temp;
    sort(sorted_rez_nd.begin(), sorted_rez_nd.end());
    
    int m_size = sorted_rez_nd.size();
    
    // Mediana
    if (m_size % 2 != 0)
        grupe.setMed(sorted_rez_nd[m_size / 2]);
    else
        grupe.setMed((sorted_rez_nd[m_size / 2 - 1] + sorted_rez_nd[m_size / 2]) / 2.0);

    // Vidurkis
    double sum = 0;
    for (int i = 0; i < m_size; ++i) {
        sum += sorted_rez_nd[i];
    }
    grupe.setVid(sum / m_size);
}

void Student_class::pasirinkimas4(vector<Student_class>& grupe) {
    system("dir *.txt");
    string filename;
    cout << "Irasykite duomenu failo pavadinima (duomenysn.txt): ";
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
        //Read data for each student from the file
        auto start = chrono::high_resolution_clock::now();
        int eilutes=0;
        while (getline(file, line)) {
            
            eilutes++;
            Student_class student; //Create a new student object
            string vardas, pavarde;
            istringstream iss(line);
            iss >> vardas >> pavarde;
            student.setVard(vardas);
            student.setPav(pavarde);

            //Resize rez_nd based on the expected size
            student.getRezNd().resize(expected_size, 0.0);

            //Read rez_nd values
            for (int j = 0; j < expected_size; ++j) {
                double rez_nd_temp;
                if (!(iss >> rez_nd_temp)) {
                    //Handle the case where there are fewer values than expected
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
            grupe.push_back(student); //Add the student to the vector
        }

        chrono::duration<double> diff = chrono::high_resolution_clock::now()-start; //Skirtumas (s)
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

        //galutinis
        double a = -1;
        for (int i = 0; i < grupe.size(); i++) {
            if (vid_med == "v") a = grupe[i].getVid();
            else if (vid_med == "m") a = grupe[i].getMed();
            double galutinis = (0.4 * a) + (0.6 * grupe[i].getRezEgz());
            grupe[i].setGalutIv(galutinis);
        }
        sorting(grupe);

        fr << "Vardas              Pavarde             "; if (vid_med == "v") fr <<"Galutinis (Vid.)"<< endl;
                                                else if (vid_med == "m") fr <<"Galutinis (Med.)"<< endl;
        fr << "--------------------------------------------------------" << endl;
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < grupe.size(); i++) {
            fr << left << setw(20) << grupe[i].getVard() << left << setw(20) << grupe[i].getPav() << left << setw(20) << setprecision(3) << grupe[i].getGalutIv() << endl;
        }
        diff = chrono::high_resolution_clock::now()-start; //Skirtumas (s)
        fr << "--------------------------------------------------------\n";
        fr <<"Irasyti duomenis uztruko: "<< diff.count() << " s\n";
        fr.close();

    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
    grupe.clear();
}

void Student_class::sorting(vector<Student_class>& grupe){
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
    case 'v': //pagal varda
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
    case 'p': //pagal pavarde
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
    case 'g': //pagal galutini ivertinima
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

void Student_class::pasirinkimas6(vector<Student_class>& grupe, string& filename2, int& duom, chrono::duration<double>& duom_create_diff) {
    system("dir *.txt");
    string filename;
    cout << "Irasykite duomenu failo pavadinima (rezultatain.txt): ";
    cin >> filename;

    vector<Student_class> vargsai;

    stringstream my_buffer;
    ifstream file(filename);
    if (!file) {
        cerr << "Klaida: Nepavyko atidaryti failo\n";
        return;
    }

    my_buffer << file.rdbuf();
    file.close();

    vector<string> splited;
    string line;

    while (getline(my_buffer, line)) {
        splited.push_back(line);
    }

    int eilutes = 0;
    auto duom_read_start = chrono::high_resolution_clock::now();
    for (const string& line : splited) {
        istringstream iss(line);
        Student_class student;

        string vardas, pavarde; //temp

        if (!(iss >> vardas >> pavarde)) {
            cerr << "Klaida: Nepavyko nuskaityti vardu ir pavardziu\n";
            continue;
        }

        student.setVard(vardas);
        student.setPav(pavarde);

        double grade;
        while (iss >> grade) {
            student.addGradeToRezNd(grade);
        }
        vector<double> grades = student.getRezNd();

        if (student.isRezNdEmpty()) {
            cerr << "Klaida: Nepavyko nuskaityti pazymiu\n";
            continue;
        }

        student.setRezEgzFromRezNd();

        chrono::high_resolution_clock::time_point end_reading = chrono::high_resolution_clock::now();

        eilutes++;

        MedianaVidurkis(student);

        grupe.push_back(move(student));
    }

    chrono::duration<double> duom_read_diff = chrono::high_resolution_clock::now() - duom_read_start;

    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do {
        cin >> vid_med;
        if (vid_med != "v" && vid_med != "m") cout << "Netinkama ivestis(irasykite 'v' arba 'm'): ";
    } while (vid_med != "v" && vid_med != "m");

    //galutinis
    double a = -1;
    for (int i = 0; i < grupe.size(); i++) {
        double a = (vid_med == "v") ? grupe[i].getVid() : grupe[i].getMed();
        double galutinis = (0.4 * a) + (0.6 * grupe[i].getRezEgz());
        grupe[i].setGalutIv(galutinis);
    }

    auto duom_sort_start = chrono::high_resolution_clock::now();
    saunuoliai_vargsai(grupe, vargsai);
    chrono::duration<double> duom_sort_diff = chrono::high_resolution_clock::now() - duom_sort_start;

    cout << "Rusiuojami saunuoliai" << endl;
    sorting(grupe);
    cout << "Rusiuojami vargsai" << endl;
    sorting(vargsai);

    string ofstreamfile = "saunuoliai" + to_string(eilutes) + ".txt";
    ofstream saunuoliai_file(ofstreamfile);
    auto duom_write_start = chrono::high_resolution_clock::now();
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

    chrono::duration<double> duom_write_diff = chrono::high_resolution_clock::now() - duom_write_start;

    cout << "***********************************************************" << endl;
    cout << "Nuskaityti " << eilutes << " irasu uztruko: " << duom_read_diff.count() << " s\n";
    cout << "Surikiuoti " << eilutes << " irasu uztruko: " << duom_sort_diff.count() << " s\n";
    cout << "Irasyti " << eilutes << " irasu uztruko: " << duom_write_diff.count() << " s\n";
    cout << "***********************************************************" << endl;
    cout << endl;

    grupe.clear();
    vargsai.clear();
}

void Student_class::duomenu_sukurimas(vector<Student_class>& grupe, chrono::duration<double>& duom_create_diff, int& duom){
    cout << "Kiek eiluciu duomenu generuoti? ";
    cin >> duom;
    string filename2="duomenys" + to_string(duom) + ".txt";
    auto duom_create_start = chrono::high_resolution_clock::now();
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
    duom_create_diff = chrono::high_resolution_clock::now()-duom_create_start;
}

void Student_class::saunuoliai_vargsai(vector<Student_class>& grupe, vector<Student_class>& vargsai) {
    //Partition the grupe vector based on below_5 condition using a lambda function
    auto partition_point = partition(grupe.begin(), grupe.end(), [](const Student_class& student) {
        return student.getGalutIv() < 5;
    });

    //Move the partitioned elements to vargsai
    move(partition_point, grupe.end(), back_inserter(vargsai));

    //Erase the partitioned elements from grupe
    grupe.erase(partition_point, grupe.end());
}

bool below_5(const Student_class& student) {
    return student.getGalutIv() < 5;
}

void Student_class::testas() {
    cout << endl << endl;


    //Zmogus objzmg("Jonas", "Jonaitis");


    // Create an object
    Student_class obj1("vardas", "pavarde", {0}, 0, 0, 0, 0); // Initialize with initial values
    cin >> obj1; // Input data from the user

    // Print the object
    cout << "duomenys panaudojant: ostream& operator<<(ostream& os, const Student_class& student) " << obj1 << endl;

    // Test copy constructor
    Student_class obj2(obj1);
    cout << "Copy constructor: " << obj2 << endl;

    // Test copy assignment operator
    Student_class obj3;
    obj3 = obj1;
    cout << "Copy assignment operator: " << obj3 << endl;

    //clear();
    cout << "destructor: " << obj1 << endl << endl;

    // Test move constructor
    Student_class obj4(move(obj1));
    cout << "Move constructor: " << obj4 << endl;

    // Test move assignment operator
    Student_class obj5;
    obj5 = move(obj2);
    cout << "Move assignment operator: " << obj5 << endl;

}