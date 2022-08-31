#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student {
    private:
        int scores[5];
    public:
        void input();
        int calculateTotalScore();
        ~Student();
        Student();
};

void Student::input() {
    for (int i=0; i<5; i++ ) 
        cin >> this->scores[i];
}

int Student::calculateTotalScore() {
    int cnt = 0;
    for (int i=0; i<5; i++ )
        cnt = cnt + this->scores[i];
    return cnt;
}

Student::~Student(){
}
Student::Student(){
    for (int i=0; i<5; i++)
        this->scores[i] = 0;
}

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}