#include <iostream>
using namespace std;

class A {
    private:
    int a, b;
    int *p;
    
    public:
    A(int a, int b){
        this->a = a;
        this->b = b;
    }
    A (int a, int b, int c) {
        this->a = a;
        this->b = b;
        p = new int;
        *p = c;
    }
    A operator =(A &Ai) {
        A o_A(Ai.a, Ai.b);
        o_A.p = new int;
        *(o_A.p) = *(Ai.p);
        return o_A;
    }
    void setData(int a, int b, int c) {
        this->a = a;
        this->b = b;
        *p = c;
    }
    void showData() {
        cout << "a: " << a << " b: " << b << endl;
        cout << "Value stored in pointer p: " << *p << endl;
    }
};



int main() {
    A objA1(3,4,5), objA2(7,8,9);
    
    objA1.showData();
    objA2.showData();
    
    objA2 = objA1;
    
    objA2.setData(10,11,12);
    objA1.showData();
    objA2.showData();
    
    return 0;
}