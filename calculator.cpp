#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class
class Student
{
protected:
    string name;
    int id;
    vector<float> grades;

public:
    void setStudentinfo(const string &studentName, int studentid)
    {
        name = studentName;
        id = studentid;
    }

    void setGrades(const vector<float> &studentGrades)
    {
        grades = studentGrades;
    }

    void displayStudentinfo() const
    {
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << id << endl;
    }
};

// Derived class
class CGPACalculator : public Student
{
public:
    float calculateCGPA() const
    {
        if (grades.empty())
            return 0.0f;
        float total = 0.0f;
        for (float grade : grades)
        {
            total += grade;
        }
        return total / grades.size();
    }

    void displayCGPA() const
    {
        cout << "CGPA: " << calculateCGPA() << endl;
    }
};

int main()
{
    const int studentCount = 3;
    vector<CGPACalculator> students(studentCount);

    // Input details for each student
    for (int i = 0; i < studentCount; ++i)
    {
        string name;
        int id;
        int subjectCount;
        vector<float> grades;

        cout << "Enter details for Student " << i + 1 << "\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "ID: ";
        cin >> id;

        cout << "Number of subjects: ";
        cin >> subjectCount;

        grades.resize(subjectCount);
        cout << "Enter grades (out of 4.0): ";
        for (int j = 0; j < subjectCount; ++j)
        {
            cin >> grades[j];
        }

        students[i].setStudentinfo(name, id);
        students[i].setGrades(grades);
    }

    // Display details and CGPA for each student
    cout << "\nStudent Details and CGPA:\n";
    for (int i = 0; i < studentCount; ++i)
    {
        cout << "\nStudent " << i + 1 << "\n";
        students[i].displayStudentinfo();
        students[i].displayCGPA();
    }

    return 0;
}