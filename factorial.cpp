#include<iostream>

using namespace std;

int fact(int n) {
    if (n==1)
        return 1;
    else {
        return n*fact(n-1);
    }
}

int main() {
    int N = 4;
    cout << "Factorial of " << N << " is: " << fact(N) << endl;
    return 0;
}