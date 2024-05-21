#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <chrono>

using namespace std;

class Zmogus {
protected:
    string vard_, pav_;

    Zmogus(const string& vard, const string& pav) //constructor'ius protected = no zmogus objects
            : vard_(vard), pav_(pav) {}
public:

    virtual ~Zmogus() = default;
};

class Student_class : public Zmogus {
private:
    vector<double> rez_nd_;
    double rez_egz_;
    double vid_;
    double med_;
    double galut_iv_;

    void clear() {
        vard_.clear();
        pav_.clear();
        rez_nd_.clear();
        rez_egz_ = 0.0;
        vid_ = 0.0;
        med_ = 0.0;
        galut_iv_ = 0.0;
    }

public:
    Student_class();
    Student_class(string vard, string pav, vector<double> rez_nd, double rez_egz, double vid, double med, double galut_iv);
    ~Student_class();

    Student_class(const Student_class& other);
    Student_class& operator=(const Student_class& other);
    Student_class(Student_class&& other) noexcept;
    Student_class& operator=(Student_class&& other) noexcept;

    friend istream& operator>>(istream& is, Student_class& student);
    friend ostream& operator<<(ostream& os, const Student_class& student);

    string getVard() const { return vard_; }
    string getPav() const { return pav_; }
    vector<double> getRezNd() const { return rez_nd_; }
    double getRezEgz() const { return rez_egz_; }
    double getVid() const { return vid_; }
    double getMed() const { return med_; }
    double getGalutIv() const { return galut_iv_; }

    void setVard(const string& vard) { vard_ = vard; }
    void setPav(const string& pav) { pav_ = pav; }
    void setRezNd(const vector<double>& rez_nd) { rez_nd_ = rez_nd; }
    void setRezEgz(double rez_egz) { rez_egz_ = rez_egz; }
    void setVid(double vid) { vid_ = vid; }
    void setMed(double med) { med_ = med; }
    void setGalutIv(double galut_iv) { galut_iv_ = galut_iv; }

    void addGradeToRezNd(double grade) { rez_nd_.push_back(grade); }

    bool isRezNdEmpty() const { return rez_nd_.empty(); }

    void setRezEgzFromRezNd() {
        if (!rez_nd_.empty()) {
            rez_egz_ = rez_nd_.back();
        }
    }

    void pasirinkimas1(vector<Student_class>& grupe);
    void pasirinkimas2(vector<Student_class>& grupe);
    void pasirinkimas3(vector<Student_class>& grupe);
    void pasirinkimas6(vector<Student_class>& grupe, string& filename2, int& duom, chrono::duration<double>& duom_create_diff);
    void printrez(vector<Student_class>& grupe);
    void MedianaVidurkis(Student_class& student);
    void pasirinkimas4(vector<Student_class>& grupe);
    void sorting(vector<Student_class>& grupe);
    void saunuoliai_vargsai(vector<Student_class>& grupe, vector<Student_class>& vargsai);
    void duomenu_sukurimas(vector<Student_class>& grupe, chrono::duration<double>& duom_create_diff, int& duom);
    bool below_5(const Student_class& student);
    void testas();
};



#endif
