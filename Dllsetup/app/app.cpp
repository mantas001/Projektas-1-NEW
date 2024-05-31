#include "../Dll/Dll.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;

int main() {
    srand(time(NULL));
    Student_class grupe; //Create an instance of the Student_class
    vector<Student_class> student_group;
    string filename2;
    int duom;
    std::chrono::duration<double> duom_create_diff;
    string pasirinkimas;
    do {
        do {
            cout << "1 - Ivesti duomenis ranka" << endl;
            cout << "2 - Generuoti pazymius" << endl;
            cout << "3 - Generuoti ir pazymius, ir studentu vardus, ir pavardes" << endl;
            cout << "4 - Skaityti duomenis is failo" << endl;
            cout << "5 - Generuoti naujus duomenis" << endl;
            cout << "6 - Suskirstyti studentus" << endl;
            cout << "7 - Baigti darba" << endl;
            cout << "testas - testas uzduociai" << endl;
            cout << "Pasirinkimas: ";
            cin >> pasirinkimas;
        } while (!(pasirinkimas == "1" || pasirinkimas == "2" || pasirinkimas == "3" || pasirinkimas == "4" || pasirinkimas == "5" || pasirinkimas == "6" || pasirinkimas == "7" || pasirinkimas == "testas"));
        if (pasirinkimas == "1")      grupe.pasirinkimas1(student_group); // Call member function on the instance of Student_class
        else if (pasirinkimas == "2") grupe.pasirinkimas2(student_group);
        else if (pasirinkimas == "3") grupe.pasirinkimas3(student_group);
        else if (pasirinkimas == "4") grupe.pasirinkimas4(student_group);
        else if (pasirinkimas == "5") grupe.duomenu_sukurimas(student_group, duom_create_diff, duom);
        else if (pasirinkimas == "6") grupe.pasirinkimas6(student_group, filename2, duom, duom_create_diff);
        else if (pasirinkimas == "testas") grupe.testas();
        else if (pasirinkimas == "7") {
            cout << "Programa darba baige" << endl;
            break;
        }
        else cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";

    } while (pasirinkimas != "7");
    return 0;
}
