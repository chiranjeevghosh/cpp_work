#include<iostream>
#include<string>

using namespace std;

string reverse_str(string& s) {
    string ans_s;
    for (int i=s.size()-1; i>=0; i--) {
        //ans_s+=s[i];
        ans_s.push_back(s[i]);
    }
    return ans_s;
}

int main() {
    string s = "asd asdfagf ghgdhdh";
    string ans_s = reverse_str(s);
    cout << ans_s << endl;
    return 0;
}