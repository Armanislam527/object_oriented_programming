#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <vector>
#include <string>
#include <iostream>

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

    QString getStudentDetails() const
    {
        QString details = QString::fromStdString("Name: " + name + "\nID: " + std::to_string(id) + "\nCGPA: " + std::to_string(calculateCGPA()));
        return details;
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("CGPA Calculator");

    QVBoxLayout *layout = new QVBoxLayout();

    QLineEdit *nameInput = new QLineEdit();
    nameInput->setPlaceholderText("Enter Student Name");
    layout->addWidget(nameInput);

    QLineEdit *idInput = new QLineEdit();
    idInput->setPlaceholderText("Enter Student ID");
    layout->addWidget(idInput);

    QLineEdit *gradesInput = new QLineEdit();
    gradesInput->setPlaceholderText("Enter Grades (comma separated)");
    layout->addWidget(gradesInput);

    QLabel *resultLabel = new QLabel("CGPA will appear here");
    layout->addWidget(resultLabel);

    QPushButton *calculateButton = new QPushButton("Calculate CGPA");
    layout->addWidget(calculateButton);

    QObject::connect(calculateButton, &QPushButton::clicked, [&]() {
        CGPACalculator student;
        student.setStudentinfo(nameInput->text().toStdString(), idInput->text().toInt());

        vector<float> grades;
        QStringList gradeList = gradesInput->text().split(",");
        for (const QString &grade : gradeList)
        {
            grades.push_back(grade.toFloat());
        }
        student.setGrades(grades);

        resultLabel->setText(student.getStudentDetails());
    });

    window.setLayout(layout);
    window.show();

    return app.exec();
}
