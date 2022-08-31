// https://www.programiz.com/cpp-programming/virtual-functions

#include<iostream>
#include<string.h>

using namespace std;

class Animal {
    protected:
        string type;

    public:
        Animal() {
            type = "Animal";
        }
        virtual string getType() {
            return type;
        }
        void print();
};


class Dog: public Animal {
    public:
        Dog() {
            type = "Dog";
        }
        string getType() {
            return type;
        }
};

class Cat: public Animal {
    public:
        Cat() {
            type = "Cat";
        }
        string getType() {
            return type;
        }
};

void Animal::print() {
    cout << "Animal: " << this->getType() << endl;
}

int main() {
    Animal *p0 = new Animal();
    Animal *p1 = new Dog();
    Animal *p2 = new Cat();
    p0->print();
    p1->print();
    p2->print();
    return 0;
}