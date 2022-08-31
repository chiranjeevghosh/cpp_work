#include<iostream>
#include<unordered_map>


// make_pair()
// insert()
// first, second
// iterator
// erase
// empty()

using namespace std;

int main() {
    unordered_map<int,int> map_;
    if (map_.empty())
        cout << "Map is empty right now" << endl;
    for (int i=5; i>=0; i--) {
        map_.insert(make_pair(i,3*i));
    }
    unordered_map<int,int>::iterator it = map_.begin();
    while(it != map_.end()) {
        cout << it->first << ' ' << it->second << endl;
        it++;
    }
    cout << endl;
    for (int i=0; i<2; i++) {
        map_.erase(i);
    }
    it = map_.begin();
    while(it != map_.end()) {
        cout << it->first << ' ' << it->second << endl;
        it++;
    }
    return 0;
}