#include <iostream>

#include <cstdio>
using namespace std;

struct Node {
    int info;
    Node *next;
};

class List {
    private:
    Node *START;
    public:
    List() {
        START = NULL;
    }
    void CreateNode (int data) {
        Node *N;
        N = new Node;
        if (START == NULL) {
            N->info = data;
            N->next = NULL;
        }
        else {
            Node *temp;
            temp = START;
            N->info = data;
            N->next = temp;
        }
        START = N;
    }
    void DeleteNode () {
        if (START == NULL)
            cout << "WARNING: There's no node to delete" << endl;
        else{
            cout << "Deleting first node" << endl;
            if (START->next == NULL)
                START = NULL;
            else
                START = START->next;
        }
    }
    void ViewList () {
        if (START == NULL)
            cout << "WARNING: Empty List" << endl;
        else {
            Node *t;
            t = START;
            int count = 0;
            while (t != NULL) {
                cout << "Value at node " << ++count << " is " << t->info << endl;
                t = t->next;
            }
            cout << "All list contents have been viewed" << endl;
        }
    }
};


int main() {
    int entry;
    List list;
    cout << "1. Add Value to the List" << endl;
    cout << "2. Delete First Value" << endl;
    cout << "3. View List" << endl;
    cout << "4. Exit" << endl;
    
    while(true) {
        cout << "Enter Your Option: ";
        cin >> entry;
        switch (entry) {
            case 1:
                int val;
                cout << "Enter Value: ";
                cin >> val;
                list.CreateNode(val);
                break;
            case 2:
                list.DeleteNode();
                break;
            case 3:
                list.ViewList();
                break;
            case 4:
                return 0;
                break;
            default:
                cout << "Invalid Entry, Try Again!" << endl;
                break;
        }
    }
    return 0;
    
    
}