#include<iostream>
#include<array>
#include<tuple>

using namespace std;

int main() {
    array<int,10> a={10,123,4,5,0};
    pair<int,string> p;
    tuple<int,string,float> t;
    p = make_pair(2,"Ghosh");
    t = make_tuple(3,"Pal",23.45f);

    cout << "ARRAY" << endl;
    for (int i=0; i<a.size(); i++) {
        cout << i << ": " << a.at(i) << " ";
    }
    cout << endl;
    cout << "PAIR" << endl;
    cout << "p0: " << p.first << " p1: " << p.second << endl;
    cout << "TUPLE" << endl;
    cout << "t0: " << get<0>(t) << " t1: " << get<1>(t) << " t2: " << get<2>(t) << endl;
    return 0;
}