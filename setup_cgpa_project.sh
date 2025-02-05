#!/bin/bash

# Define project variables
PROJECT_NAME="CGPACalculator"
SOURCE_FILE="/home/arman/arman/github/object_oriented_programming/cgpa_calculator.cpp"
PROJECT_DIR="/home/arman/arman/github/object_oriented_programming/$PROJECT_NAME"

# Check if the source file exists
if [[ ! -f "$SOURCE_FILE" ]]; then
    echo "Error: Source file does not exist at $SOURCE_FILE"
    exit 1
fi

# Create project directory
mkdir -p "$PROJECT_DIR"
cd "$PROJECT_DIR" || exit

# Create Qt project files
echo "Creating Qt project files..."

# main.cpp
cat <<EOL > main.cpp
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
        QString details = QString::fromStdString("Name: " + name + "\\nID: " + std::to_string(id) + "\\nCGPA: " + std::to_string(calculateCGPA()));
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
EOL

# Create .pro file
echo "Generating .pro file..."
cat <<EOL > $PROJECT_NAME.pro
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = $PROJECT_NAME
TEMPLATE = app

SOURCES += main.cpp
EOL

# Compile the project
echo "Compiling the project..."
qmake && make

# Run the application
if [[ -f "./$PROJECT_NAME" ]]; then
    echo "Running the application..."
    ./$PROJECT_NAME
else
    echo "Error: Compilation failed."
    exit 1
fi
