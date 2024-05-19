#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <chrono>

class Student_class {
private:
    std::string vard_, pav_;
    std::vector<double> rez_nd_;
    double rez_egz_;
    double vid_;
    double med_;
    double galut_iv_;

public:

    Student_class();
    Student_class(std::string vard, std::string pav, std::vector<double> rez_nd, double rez_egz, double vid, double med, double galut_iv);
    ~Student_class(); // Destructor

    std::string getVard() const { return vard_; }
    void setVard(const std::string& vard) { vard_ = vard; }

    std::string getPav() const { return pav_; }
    void setPav(const std::string& pav) { pav_ = pav; }

    std::vector<double> getRezNd() const { return rez_nd_; }
    void setRezNd(const std::vector<double>& rez_nd) { rez_nd_ = rez_nd; }

    double getRezEgz() const { return rez_egz_; }
    void setRezEgz(double rez_egz) { rez_egz_ = rez_egz; }

    double getVid() const { return vid_; }
    void setVid(double vid) { vid_ = vid; }

    double getMed() const { return med_; }
    void setMed(double med) { med_ = med; }

    double getGalutIv() const { return galut_iv_; }
    void setGalutIv(double galut_iv) { galut_iv_ = galut_iv; }

    void addGradeToRezNd(double grade) { rez_nd_.push_back(grade); }

    bool isRezNdEmpty() const { return rez_nd_.empty(); }

    void setRezEgzFromRezNd() {
        if (!rez_nd_.empty()) {
            rez_egz_ = rez_nd_.back();
        }
    }

    void pasirinkimas1(std::vector<Student_class>& grupe);
    void pasirinkimas2(std::vector<Student_class>& grupe);
    void pasirinkimas3(std::vector<Student_class>& grupe);
    void pasirinkimas6(std::vector<Student_class>& grupe, std::string& filename2, int& duom, std::chrono::duration<double>& duom_create_diff);
    void printrez(std::vector<Student_class>& grupe);
    void MedianaVidurkis(Student_class& student);
    void pasirinkimas4(std::vector<Student_class>& grupe);
    void sorting(std::vector<Student_class>& grupe);
    void saunuoliai_vargsai(std::vector<Student_class>& grupe, std::vector<Student_class>& vargsai);
    void duomenu_sukurimas(std::vector<Student_class>& grupe, std::chrono::duration<double>& duom_create_diff, int& duom);
    bool below_5(const Student_class& student);
};

#endif
