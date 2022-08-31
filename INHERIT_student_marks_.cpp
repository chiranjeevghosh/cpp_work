#include<iostream>

using namespace std;

class Student {
    private:
        char Name[30];
        int Age;
        char City[16];
    
    public:
        void getBasicInfo() {
            cout << "Enter student's basic information" << endl;
            cout << "Enter student name: "; cin.getline(Name,sizeof(Name));
            cout << "Enter student age: "; cin >> Age;
            cout << "Enter city of student address: "; cin >> City;
        }
        void displayInfo() {
            cout << "Name: " << Name << endl;
            cout << "Age: " << Age << endl;
            cout << "City: " << City << endl;
        }

};

class Results: public Student {
    private:
        int Marks;
        float Perc;

    public:
        void getMarks() {
            cout << "Enter marks out of 500: "; cin >> Marks;
        }
        void displayPerc() {
            displayInfo();
            Perc = Marks*100.0/500.0;
            cout << "Perc: " << Perc << "%" << endl; 
        }
};

int main() {
    Results *s;
    s = new Results;
    s->getBasicInfo();
    s->getMarks();
    s->displayPerc();

    return 0;
}