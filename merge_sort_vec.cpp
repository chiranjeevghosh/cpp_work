#include<iostream>
#include<vector>

using namespace std;

vector<int> mergeSort(vector<int> A, vector<int> B) {
   
    
    
    vector<int>::iterator it_a = A.begin();
    vector<int>::iterator it_b = B.begin();

    while (it_a != A.end() && it_b != B.end()) {
        if (*it_a > *it_b) {
            it_a = A.insert(it_a,*it_b);
            it_b++;
        }
        it_a++;

    }
    if (it_a == A.end()) {
        while(it_b != B.end()) {
            A.push_back(*it_b);
            it_b++;
        }
    }

    
    return A;
}

int main() {
    vector<int> A{2, 7};
    vector<int> B{3, 9, 16};
    vector<int> C = mergeSort(A,B);

    vector<int>::iterator it_c = C.begin();
    
    while(it_c != C.end()) {
        cout << *it_c << ' ' << endl;
        it_c++;
    }
    return 0;
}