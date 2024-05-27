#include "pch.h"
#include "functions_test.h"
#include <iostream>
#include <utility> // for std::move

using namespace std;

const int M = 15; // namu darbu uzduociu kiekis kai generuojama atsitiktinai

Student_class::Student_class()
    : Zmogus("", ""), rez_nd_(), rez_egz_(0.0), vid_(0.0), med_(0.0), galut_iv_(0.0) {}

Student_class::Student_class(string vard, string pav, vector<double> rez_nd, double rez_egz, double vid, double med, double galut_iv)
    : Zmogus(vard, pav), rez_nd_(rez_nd), rez_egz_(rez_egz), vid_(vid), med_(med), galut_iv_(galut_iv) {}

Student_class::~Student_class() {
    cout << "Destructor called!" << endl;
    clear();
}

Student_class::Student_class(const Student_class& other)
    : Zmogus(other.vard_, other.pav_), rez_nd_(other.rez_nd_), rez_egz_(other.rez_egz_), vid_(other.vid_), med_(other.med_), galut_iv_(other.galut_iv_) {}

Student_class& Student_class::operator=(const Student_class& other) {
    if (this != &other) {
        Zmogus::operator=(other); // call base class assignment operator
        rez_nd_ = other.rez_nd_;
        rez_egz_ = other.rez_egz_;
        vid_ = other.vid_;
        med_ = other.med_;
        galut_iv_ = other.galut_iv_;
    }
    return *this;
}

Student_class::Student_class(Student_class&& other) noexcept
    : Zmogus(std::move(other.vard_), std::move(other.pav_)), rez_nd_(std::move(other.rez_nd_)), rez_egz_(other.rez_egz_), vid_(other.vid_), med_(other.med_), galut_iv_(other.galut_iv_) {
    other.clear();
}

Student_class& Student_class::operator=(Student_class&& other) noexcept {
    if (this != &other) {
        Zmogus::operator=(std::move(other)); // call base class move assignment operator
        rez_nd_ = std::move(other.rez_nd_);
        rez_egz_ = other.rez_egz_;
        vid_ = other.vid_;
        med_ = other.med_;
        galut_iv_ = other.galut_iv_;
        other.clear();
    }
    return *this;
}

istream& operator>>(istream& is, Student_class& student) {
    string vard, pav;
    cout << "Enter student's first and last name: ";
    is >> vard >> pav;
    student.setVard(vard);
    student.setPav(pav);
    return is;
}

ostream& operator<<(ostream& os, const Student_class& student) {
    os << student.getVard() << " " << student.getPav();
    return os;
}
