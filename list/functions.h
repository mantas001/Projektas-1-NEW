#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <list> // Include list header
#include <string>
#include <chrono>

struct stud {
    std::string vard, pav;
    std::list<double> rez_nd; // Change vector to list
    double rez_egz;
    double vid;
    double med;
    double galut_iv;
};

void pasirinkimas1(std::list<stud>& grupe); // Modify function signatures to use list
void pasirinkimas2(std::list<stud>& grupe);
void pasirinkimas3(std::list<stud>& grupe);
void pasirinkimas6(std::list<stud>& grupe, std::string& filename2, int& duom, std::chrono::duration<double>& duom_create_diff);
void printrez(std::list<stud>& grupe);
void MedianaVidurkis(stud& grupe);
void pasirinkimas4(std::list<stud>& grupe);
void sorting(std::list<stud>& grupe);
void saunuoliai_vargsai(std::list<stud>& grupe, std::list<stud>& vargsai);
void duomenu_sukurimas(std::list<stud>& grupe, std::chrono::duration<double>& duom_create_diff, int& duom);
bool below_5(const stud& student);
#endif
