#include<iostream>
#include<list>


// pop_front()
// pop_back()
// push_back()
// push_front()
// reverse()
// sort()


using namespace std;

void showList(list<int> li) {
    list<int>::iterator it;
    it = li.begin();
    while(it != li.end()) {
        cout << '\t' << *it;
        it++; 
    }
    cout << '\n';
}

int main() {
    list<int> li1, li2;
    for (int i=0; i<10; i++) {
        li1.push_back(i*2);
        li2.push_front(i*3);
    }
    cout << "\n List 1 is: ";
    showList(li1);
    cout << "\n List 2 is: ";
    showList(li2);

    cout << "\nli1.pop_front(): ";
    li1.pop_front();
    showList(li1);

    cout << "\nli2.pop_back(): ";
    li2.pop_back();
    showList(li2);

    cout << "\nli1.reverse(): ";
    li1.reverse();
    showList(li1);

    cout << "\nli2.sort(): ";
    li2.sort();
    showList(li2);

    return 0;
}