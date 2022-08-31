#include<iostream>
#include<set>

using namespace std;

int main() {
    string test = "This is a test hsgodfk hakjpual mla";
    string find = "hello";
    set<char> findLetters;

    for (int i=0; i<find.length(); i++) {
        char letter = find[i];
        findLetters.insert(letter);
    }
    for (int i=0; i<test.length(); i++) {
        char letter = test[i];
        findLetters.erase(letter);
    }
    if (findLetters.size() > 0)
        cout << "No it doesn't have all letters" << endl;
    else    
        cout << "Yes it has all letters" << endl;

    return 0;
}