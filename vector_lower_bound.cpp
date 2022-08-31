#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int k,v_size;
    vector<int> v;
    cin  >> v_size;
    for(int i=0; i<v_size; i++){
        cin >> k;
        v.push_back(k);
    }
    k = 0;
    vector<int>::iterator low;
    vector<int>::iterator it;
    int q;
    cin  >> q;
    for(int Q=0; Q<q; Q++){
        cin >> k;
        low = lower_bound(v.begin(), v.end(), k);
        if (v[low - v.begin()] == k){
            cout << "Yes " << (low - v.begin() + 1)<< endl;
        }
        else{
            cout << "No " << (low - v.begin() + 1) << endl;
        }
    }
    
    return 0;
}

