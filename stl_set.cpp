#include<iostream>
#include<set>

using namespace std;

int main() {
    set<char> s1={'C', 'D', 'C', 'D'};
    s1.insert('B');
    //s1.erase('C');
     
    if (s1.find('C') == s1.end()) 
        cout << "Could not find C" << endl;
    else    
        cout << "Found C!" << endl;

    for (auto itr = s1.begin(); itr != s1.end(); ++itr) {
        cout << *itr << endl;
    }
    return 0;
}