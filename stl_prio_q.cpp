#include<iostream>
#include<stdlib.h>
#include<queue>

// push()
// empty()
// top()
// pop()

using namespace std;

int main() {
    priority_queue<int> Q;
    int N;

    cout << "Enter input values in queue: "; cin >> N;
    int k = 0;
    for (int i=0; i<N; i++) {
        k = rand()%N + 1;
        cout << ' ' << k;
        Q.push(k);
    }
    cout << endl;
    while (!Q.empty()) {
        cout << ' ' << Q.top();
        Q.pop();
    }
    return 0;
}