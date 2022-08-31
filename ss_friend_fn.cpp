#include<iostream>

using namespace std;

class B;
class A {
    private:
        int x;
    public:
        A(int i) {
            x = i;
        }
        friend int operator+(A,B);
};
class B {
    private:
        int y;
    public:
        B(int j) {
            y = j;
        }
        friend int operator+(A,B);
};

int operator+(A obj_a, B obj_b) {
    return (obj_a.x + obj_b.y);
}
int main() {
    A a(9);
    B b(6);

    cout << "A + B: " << a+b << endl;
    return 0;
}