#include<iostream>
#include<stack>
#include<stdlib.h>


// push()
// top()
// pop()
// size()
// empty()

using namespace std;

int main() {

    stack<int> S;
    int N;

    cout << "Enter input values in stack: "; cin >> N;
    int k = 0;
    for (int i=0; i<N; i++) {
        k = rand()%N + 1;
        cout << ' ' << k;
        S.push(k);
    }
    cout << endl;
    
    while (!S.empty()) {
        cout << ' ' << S.top();
        S.pop();
    }


    return 0;
}