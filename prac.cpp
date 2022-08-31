#include<iostream>
#include<vector>
#include<string>

using namespace std;

class operator_if {
    public:
        int a, b;
        virtual int result() = 0;
        virtual void op_id() = 0;
};

class add : public operator_if {
    public:
        add (const int& i1, const int& i2) {
            a = i1;
            b = i2;
        }
        int result() {
            return a+b;
        }
        void op_id() {
            cout << "ADD: ";
        }
};

class sub : public operator_if {
    public:
        sub (const int& i1, const int& i2) {
            a = i1;
            b = i2;
        }
        int result() {
            return a-b;
        }
        void op_id() {
            cout << "SUBTRACT: ";
        }
};

class mul : public operator_if {
    public:
        mul (const int& i1, const int& i2) {
            a = i1;
            b = i2;
        }
        int result() {
            return a*b;
        }
        void op_id() {
            cout << "MULTIPLY: ";
        }
};

void schedule_op(operator_if *if_) {
    if_->op_id();
    cout << " " << if_->result() << endl;
}

int main() {
    int a = 20, b = 2;
    add *add_ = new add(a,b);
    schedule_op(add_);
    sub *sub_ = new sub(a,b);
    schedule_op(sub_);
    mul *mul_ = new mul(a+10,b);
    schedule_op(mul_);
    return 0;
}