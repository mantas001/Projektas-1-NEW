#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>
#include "functions.h"

using namespace std;

int main() {
    srand(time(NULL));
    vector<stud> grupe;
    string filename2;
    int duom;
    std::chrono::duration<double> duom_create_diff;
    string pasirinkimas;
    do {
        do {
            cout << "1 - Ivesti duomenis ranka"<<endl;
            cout << "2 - Generuoti pazymius"<<endl;
            cout << "3 - Generuoti ir pazymius, ir studentu vardus, ir pavardes"<<endl;
            cout << "4 - Skaityti duomenis is failo"<<endl;
            cout << "5 - Generuoti naujus duomenis"<<endl;
            cout << "6 - Suskirstyti studentus"<<endl;
            cout << "7 - Baigti darba"<<endl;
            cout << "Pasirinkimas: ";
            cin >> pasirinkimas;
        } while (!(pasirinkimas == "1" || pasirinkimas == "2" || pasirinkimas == "3" || pasirinkimas == "4"|| pasirinkimas == "5"|| pasirinkimas == "6"|| pasirinkimas == "7"));
        if (pasirinkimas=="1") pasirinkimas1(grupe);
        else if (pasirinkimas=="2") pasirinkimas2(grupe);
        else if (pasirinkimas=="3") pasirinkimas3(grupe);
        else if (pasirinkimas=="4") pasirinkimas4(grupe);
        else if (pasirinkimas=="5") duomenu_sukurimas(grupe, duom_create_diff, duom);
        else if (pasirinkimas=="6") pasirinkimas6(grupe, filename2, duom, duom_create_diff);
        else if (pasirinkimas=="7"){
            cout <<"Programa darba baige" << endl;
            break;
        }
        else cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";

    } while (pasirinkimas != "7");
    return 0;
}