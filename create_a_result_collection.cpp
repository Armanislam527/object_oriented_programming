#include <iostream>
using namespace std;
class student
{
private:
    int roll;
    float mark;

public:
    void getdata();
    void diisplay();
}; 
void student::getdata()
{
    cout << "Enter your roll and marks:";
    cin >> roll >> mark;
}
void student::diisplay()
{
    cout << "Your roll is :" << roll << " and mark is :" << mark << endl;
}
int main()
{
    student s1;
    s1.getdata();
    s1.diisplay();
}