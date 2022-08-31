#include<iostream>

using namespace std;

void bit_mask (int &num, int b1, int b2, int b3) {
   int mask_ = (1<<b1) + (1<<b2) + (1<<b3);
   num = num&(~mask_);
}

int main() {
    int N = 47;
    bit_mask(N,1,2,3);
    cout << "Masked value: " << std::hex << N << endl;
    return 0;
}