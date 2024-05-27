#include "pch.h"
#include "CppUnitTest.h"
#include "functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testas
{
    TEST_CLASS(Testas)
    {
    public:

        TEST_METHOD(TestConstructor)
        {
            // Test default constructor
            Student_class student;
            Assert::AreEqual(std::string(""), student.getVard());
            Assert::AreEqual(std::string(""), student.getPav());
            Assert::IsTrue(student.getRezNd().empty());
            Assert::AreEqual(0.0, student.getRezEgz());
            Assert::AreEqual(0.0, student.getVid());
            Assert::AreEqual(0.0, student.getMed());
            Assert::AreEqual(0.0, student.getGalutIv());

            // Test parameterized constructor
            std::vector<double> grades = { 10, 9, 8 };
            Student_class student2("Vardas", "Pavarde", grades, 9.5, 9.0, 9.0, 9.3);
            Assert::AreEqual(std::string("Vardas"), student2.getVard());
            Assert::AreEqual(std::string("Pavarde"), student2.getPav());
            Assert::AreEqual(size_t(3), student2.getRezNd().size());
            Assert::AreEqual(9.5, student2.getRezEgz());
            Assert::AreEqual(9.0, student2.getVid());
            Assert::AreEqual(9.0, student2.getMed());
            Assert::AreEqual(9.3, student2.getGalutIv());
        }

        TEST_METHOD(TestSetters)
        {
            Student_class student;
            student.setVard("Vardas");
            student.setPav("Pavarde");
            std::vector<double> grades = { 10, 9, 8 };
            student.setRezNd(grades);
            student.setRezEgz(9.5);
            student.setVid(9.0);
            student.setMed(9.0);
            student.setGalutIv(9.3);

            Assert::AreEqual(std::string("Vardas"), student.getVard());
            Assert::AreEqual(std::string("Pavarde"), student.getPav());
            Assert::AreEqual(size_t(3), student.getRezNd().size());
            Assert::AreEqual(9.5, student.getRezEgz());
            Assert::AreEqual(9.0, student.getVid());
            Assert::AreEqual(9.0, student.getMed());
            Assert::AreEqual(9.3, student.getGalutIv());
        }

        TEST_METHOD(TestAddGradeToRezNd)
        {
            Student_class student;
            student.addGradeToRezNd(10);
            student.addGradeToRezNd(9);

            std::vector<double> grades = student.getRezNd();
            Assert::AreEqual(size_t(2), grades.size());
            Assert::AreEqual(10.0, grades[0]);
            Assert::AreEqual(9.0, grades[1]);
        }

        TEST_METHOD(TestIsRezNdEmpty)
        {
            Student_class student;
            Assert::IsTrue(student.isRezNdEmpty());

            student.addGradeToRezNd(10);
            Assert::IsFalse(student.isRezNdEmpty());
        }

        TEST_METHOD(TestSetRezEgzFromRezNd)
        {
            Student_class student;
            student.addGradeToRezNd(8);
            student.addGradeToRezNd(9);
            student.setRezEgzFromRezNd();

            Assert::AreEqual(9.0, student.getRezEgz());
        }
    };
}
