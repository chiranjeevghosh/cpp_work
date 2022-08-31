#include<iostream>

using namespace std;

class Complex {
    private:
        int r, i;
    public:
        friend void operator>>(istream&, Complex&);
        friend void operator<<(ostream&, Complex);
};

void operator>>(istream &din, Complex &c) {
    din >> c.r >> c.i;
}

void operator<<(ostream &dout, Complex c) {
    dout << "Real: " << c.r << " Imag: " << c.i << endl;
}


int main() {
    Complex c;
    cout << "Enter a complex number: " << endl;
    cin >> c;
    cout << "You entered: ";
    cout << c;
    return 0;
}