#include<iostream>
#include<string>
using namespace std;
class Person {
    private:
        string name;
        int age;
    public:
        Person(string personname, int personage){
            name = personname;
            age = personage;
        }
    void introduce(){
        cout << "Hi ,I'm " << name << " and I'm " << age <<" years old"<< endl;

    }
};
int main(){
    Person person1("arman",22);
    Person person2("khadiza",21);
    person1.introduce();
    person2.introduce();

}