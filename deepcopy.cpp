#include <iostream>
using namespace std;

class A {
    private:
        int *p;
    
    public:
        A (int a){
            p = new int;
            *p = a;
        }
        A (A& Ai) {
            p = new int;
            *p = *(Ai.p);
        }
        void setData(int c) {
            *p = c;
        }
        void showData() {
            cout << "Value stored in pointer p: " << *p << endl;
        }
};



int main() {
    A objA1(10);
    //objA1.setData(10);
    A objA2 = objA1; // this will call the overwritten copy contructor
    objA2.setData(20);
    
    objA1.showData();
    objA2.showData();
    
    //objA2 = objA1;
    A objA3(30);
    objA3 = objA1; // this will call the default copy contructor
    objA3.setData(40);
    objA1.showData();
    objA2.showData();
    objA3.showData();

    
    return 0;
}