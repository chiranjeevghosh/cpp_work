#include<iostream>

using namespace std;

class Complex {
    private:
        int a, b;
    public:
        void setData(int, int);
        void displayData();
        //Complex add(Complex);
        Complex operator+(const Complex&);
};

void Complex::setData(int x, int y) {
    this->a = x;
    this->b = y;
}

/*Complex Complex::add(Complex c) {
    Complex temp;
    temp.a = this->a + c.a;
    temp.b = this->b + c.b;
    return temp;
}*/

Complex Complex::operator+(const Complex& c) {
    Complex temp;
    temp.a = this->a + c.a;
    temp.b = this->b + c.b;
    return temp;
}

void Complex::displayData() {
    cout << "Real: " << this->a << " Imag: " << this->b << endl;
}

int main () {
    Complex c1, c2;
    c1.setData(2,5);
    c2.setData(9,4);
    //Complex c3 = c1.add(c2);
    Complex c3 = c1+c2;
    c3.displayData();
    return 0;
}