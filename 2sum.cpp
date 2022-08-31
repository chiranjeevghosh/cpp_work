#include<iostream>
#include<vector>
#include<unordered_set>


using namespace std;

bool twoSum(const vector<int> &inp, int target) {
    unordered_set<int> set_;
    for (int i: inp) {
        
        if (set_.find(i) != set_.end()) {
            return true;
        }
        else {
            int c = target - i;
            set_.insert(c);
        }
    }
    return false;

}


int main() {
    vector<int> v = {1,2,4,4,6};
    int t = 10;
    cout << twoSum(v,t) << endl;
    return 0;
}