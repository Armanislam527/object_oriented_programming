#include<iostream>
#include<string>
using namespace std;
class Animal {
    public:
     virtual string speak() const = 0;
     virtual ~Animal(){ }
};
class Dog:
