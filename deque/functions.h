#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <deque>
#include <string>
#include <chrono>

struct stud {
    std::string vard, pav;
    std::deque<double> rez_nd;
    double rez_egz;
    double vid;
    double med;
    double galut_iv;
};

void pasirinkimas1(std::deque<stud>& grupe);
void pasirinkimas2(std::deque<stud>& grupe);
void pasirinkimas3(std::deque<stud>& grupe);
void pasirinkimas6(std::deque<stud>& grupe, std::string& filename2, int& duom, std::chrono::duration<double>& duom_create_diff);
void printrez(std::deque<stud>& grupe);
void MedianaVidurkis(stud& grupe);
void pasirinkimas4(std::deque<stud>& grupe);
void sorting(std::deque<stud>& grupe);
void saunuoliai_vargsai(std::deque<stud>& grupe, std::deque<stud>& vargsai);
void duomenu_sukurimas(std::deque<stud>& grupe, std::chrono::duration<double>& duom_create_diff, int& duom);
bool below_5(const stud& student);

#endif