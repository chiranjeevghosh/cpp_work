#include<iostream>
#include<queue>
#include<stdlib.h>

using namespace std;



int main() {
    /*priority_queue<int> pq;

    for (int i = 0; i < 6; i++) {
        pq.push(rand()%20);
    }
    for (int i=0; i<6; i++) {
        cout << "val: " << pq.top() << endl;
        pq.pop();
    }*/

    vector<vector<int>> v;
    v = {
        {1,2},
        {4,6},
        {2,8},
        {3,4},
        {7,7},
        {7,3}
        };
    vector<int> v1(5,0);
    
    cout << "Size of vector: " << v1.size() << endl;
    cout << "v1,2 " << v1.at(2) << endl;

    return 0;
}