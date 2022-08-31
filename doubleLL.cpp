#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        Node(Node *p, Node *n, int d): prev(p), next(n), data(d) {} 
        Node(int d): prev(NULL), next(NULL), data(d) {}
};

class doubleLL {
    public:
        Node* HEAD;
        Node* TAIL;
        doubleLL(): HEAD(NULL), TAIL(NULL) {}
        void createNode(int);
        void deleteNode();
        void viewList(); 
};

void doubleLL::createNode (int data) {
    Node* node;
    node = new Node(data);
    if (this->HEAD != NULL) { // LL exists
        node->next = this->HEAD;
        (this->HEAD)->prev = node;
        this->HEAD = node;        
    }
    else { // First node
        this->HEAD = node;
        this->TAIL = this->HEAD;
    }
}

void doubleLL::deleteNode() {
    // Remove from tail - oldest
    if(this->HEAD != NULL) {
        Node* temp;
        temp = this->TAIL;
        if (this->HEAD != this->TAIL) {
            temp->prev->next = NULL;
            this->TAIL = temp->prev;
        }
        else {
            this->HEAD = NULL;
            this->TAIL = NULL;
        }
    }
    else 
        cout << "WARNING: No node to delete" << endl;
}

void doubleLL::viewList() {
    if(this->HEAD != NULL) {
        int count = 0;
        Node* temp;
        temp = this->HEAD;
        while(true) {
            cout << "Pos: " << count << " Data: " << temp->data << endl;
            if (temp->next != NULL)
                temp = temp->next;
            else    
                break;
            count++;
        }
    }
    else 
        cout << "No list to view" << endl;
}

int main() {
    int entry;
    doubleLL list;
    cout << "1. Add value to the list" << endl;
    cout << "2. Delete last value" << endl;
    cout << "3. View list" << endl;
    cout << "4. Exit" << endl;
    
    while(true) {
        cout << "Enter Your Option: ";
        cin >> entry;
        switch (entry) {
            case 1:
                int val;
                cout << "Enter Value: ";
                cin >> val;
                list.createNode(val);
                break;
            case 2:
                list.deleteNode();
                break;
            case 3:
                list.viewList();
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