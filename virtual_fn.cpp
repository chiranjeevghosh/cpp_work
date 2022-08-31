#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int prof_id = 0;
int student_id = 0;
class Person {
  protected:
    string name;
    int age;
    
  public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
       
};

class Professor : public Person {
  protected:
    int publications;
    void getdata() {
        cin >> name;
        cin >> age;
        cin >> publications;
    }
    void putdata() {
        cout << name << " " << age << " " << publications << " " << ++prof_id << endl;
    }
    public:
        ~Professor(){
            
        }
        Professor(){
            //set_id();
            //count++;
        }
    
};

class Student : public Person {
  protected:
    int marks[6];
    void getdata() {
        cin >> name;
        cin >> age;
        for (int i=0; i<6; i++)
            cin >> marks[i];
    }
    void putdata() {
        int sum = 0;
        for (int j=0; j<6; j++)
            sum = sum + marks[j];
        cout << name << " " << age << " " << sum << " " << ++student_id << endl;
    }
    public:
        ~Student(){
            
        }
        Student(){
            //set_id();
            //count++;
        }
    
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}