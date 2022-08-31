#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Vec {
 
 public:
    vector<int> arr;
    void vect_init(vector<int>);
    //Vec(int, int);
    ~Vec();
    Vec();
    
    
};
void Vec::vect_init(vector<int> arr) {
    this -> arr = arr;
}

Vec::Vec() {
}
Vec::~Vec() {
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, q, k;
    cin >> n >> q;
    Vec a[n];
    
    // Initialize the array vectors
    for (int i=0; i<n; i++) {
        cin >> k;
        vector<int> b(k);
        for (int j=0; j<k; j++) {
            cin >> b[j];
        }
        a[i].vect_init(b);
        b.clear();
    }
    
    
    // Query Start
    int y,z;
    y = 0; z = 0;
    for (int u=0; u<q; u++) {
        cin >> y >> z;
        cout << a[y].arr[z] << endl;
        y = 0; z = 0;
    }
    return 0;
}