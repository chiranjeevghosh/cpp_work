#include<iostream>

using namespace std;

void bitflip (int &a, int bit) {
    int flip = 1 << bit;
    a = a^flip;
    //cout << "Flipped value: " << std::hex << (a^flip) << endl;
}

int main(){
    int a = 15;
    bitflip(a,0);
    cout << "Flipped value: " << std::hex << a << endl;
    return 0;
}
