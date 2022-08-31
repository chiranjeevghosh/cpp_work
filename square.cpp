#include<iostream>


using namespace std;

int power(int a, int n) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return a;

    if (n%2 == 0)
        return power(a,(n/2))*power(a,(n/2));
    else
        return a*power(a,((n-1)/2))*power(a,((n-1)/2));
}

int main() {
    int a = 7, n = 7;
    cout << a << " power " << n << " is " << power(a,n) << endl; 
}