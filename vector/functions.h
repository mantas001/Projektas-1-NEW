#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <chrono>

struct stud {
    std::string vard, pav;
    std::vector<double> rez_nd;
    double rez_egz;
    double vid;
    double med;
    double galut_iv;
};

void pasirinkimas1(std::vector<stud>& grupe);
void pasirinkimas2(std::vector<stud>& grupe);
void pasirinkimas3(std::vector<stud>& grupe);
void pasirinkimas6(std::vector<stud>& grupe, std::string& filename2, int& duom, std::chrono::duration<double>& duom_create_diff);
void printrez(std::vector<stud>& grupe);
void MedianaVidurkis(stud& grupe);
void pasirinkimas4(std::vector<stud>& grupe);
void sorting(std::vector<stud>& grupe);
void saunuoliai_vargsai(std::vector<stud>& grupe, std::vector<stud>& vargsai);
void duomenu_sukurimas(std::vector<stud>& grupe, std::chrono::duration<double>& duom_create_diff, int& duom);
bool below_5(const stud& student);

#endif