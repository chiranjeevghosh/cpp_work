#include<iostream>
#include<vector>
#include<algorithm>

// size()
// push_back()
// pop_back()
// insert()
// erase()
// clear()
// front()
// back()
using namespace std;

int main() {
    vector<int> vec;

    cout << "Original vector size: " << vec.size() << endl;

    for (int i=0; i<5; i++) 
        vec.push_back(i);

    cout << "Updated vector size: " << vec.size() << endl;
    sort(vec.begin(),vec.end(),greater<int>());
    for (int i=0; i<5; i++) {
        cout << "vec[" << i << "]: " << vec[i] << endl;
    }

    vector<int>::iterator it = vec.begin();
    while(it != vec.end()) {
        cout << "Value of vec = " << *it << endl;
        it++;
    }
    return 0;
}