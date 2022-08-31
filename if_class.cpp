#include<iostream>

using namespace std;

class operation_if {
    public:
        int a, b;
        virtual int result() = 0;
};

class add: public operation_if {
    public:
        add (const int &ip1,const int &ip2) {
            a = ip1;
            b = ip2;
        }
        int result() {
            cout << "ADD: ";
            return a+b;
        }

};

class sub: public operation_if {
    public:
        sub (const int &ip1,const int &ip2) {
            a = ip1;
            b = ip2;
        }
        int result() {
            cout << "SUBTRACT: ";
            return a-b;
        }
};

class mul: public operation_if {
    public:
        mul (const int &ip1,const int &ip2) {
            a = ip1;
            b = ip2;
        }
        int result() {
            cout << "MULTIPLY: ";
            return a*b;
        }
};


void schedule (operation_if *if_){
    cout << if_->result() << endl;
}

int main() {
    int a = 20, b = 2;
    add *add_ = new add(a,b);
    schedule(add_);
    sub *sub_ = new sub(a,b);
    schedule(sub_);
    mul *mul_ = new mul(a+10,b);
    schedule(mul_);
    return 0;
}