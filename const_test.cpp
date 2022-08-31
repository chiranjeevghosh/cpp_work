#include<iostream>
#include<string>

using namespace std;
#define Y 23
enum Example {A=500, B, C};
int main() {
    const int MAX_AGE = 90;


    int *a; // just a pointer
    a = (int*)&MAX_AGE;
    cout << "a: " << ++*a << endl;

    const int *b = new int; // pointer to const
    b = &MAX_AGE; // can be reassigned since pointer is not const
    // ++*b is illegal // writing a read only location error
    cout << "b: " << *b << endl;

    int *const c = (int*)&MAX_AGE;   // const pointer // no reassignment allowed
    cout << "c: " << ++(*c) << endl;

    const int *const d = (int*)&MAX_AGE;  // const pointer to const
    // illegal cout << "d: " << ++(*d) << endl;
    cout << "d: " << *d << endl;

    Example val = C;
    cout << "Val: " << val << endl;

    return 0;
}