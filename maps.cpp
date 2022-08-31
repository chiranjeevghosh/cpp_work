#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int k;
    cin >> k;
    map<string, int> m;
    for (int i=0; i<k; i++) {
        int y;
        int z;
        string x;
        cin >> z >> x;
        cout << "z: " << z << "x: " << x << "y: " << y << endl;
        switch(z) {
            case 1:
        	cin >> y;
                bool is_in ;
                is_in = m.find(x) != m.end();
                if (is_in == 1){
                    m[x] = m[x] + y;
                 }
                else{
                    m.insert(make_pair(x,y));
                    
                    
                }
                break;
            case 2:
                m.erase(x);
                break;
            case 3:
                cout << "Name: " << x << "Score: " << m[x] << endl;
                cout << m[x] << endl;
                break;
            default:
                cout << "Something wrong" << endl;
                break;
        }
        
    }
    return 0;
}

