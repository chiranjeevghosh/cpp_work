#include<iostream>

using namespace std;
class Account {
    private:
        int balance;
        static float roi;
    public:
        
        void setBalance(int b) {
            balance = b;
        }
        static void setRoi(float r) {
            roi = r;
        }
        static void dispRoi() {
            cout << "Current ROI: " << roi << endl;
        }
};
float Account::roi=0.0;
int main() {
    Account::setRoi(5.6);
    Account::dispRoi();
    return 0;
}