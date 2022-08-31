#include<iostream>

using namespace std;

class Complex {
    private:
        int x, y;
    public:
        Complex (int a, int b) {
            x = a;
            y = b;
        }
        Complex ()
        {}
        void showData() {
            cout << "Real: " << x << " Imag: " << y << endl;
        }

        Complex operator+(Complex); 
        
};

Complex Complex::operator+(Complex c) {
    Complex temp;
    temp.x = this->x + c.x;
    temp.y = this->y + c.y;
    return temp;
}

int main() {
    Complex c1(4,6), c2(8,1);
    Complex c3 = c1+c2;
    Complex c4 = c3;
    c3.showData();
    c4.showData();
    return 0;
}