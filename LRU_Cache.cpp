#include<iostream>
#include<string>
#include <map>

using namespace std;

class Node {
    public:
        Node* prev;
        Node* next;
        int key;
        int value;
        Node(Node* p, Node* n, int k, int val): prev(p), next(n), key(k), value(val) {}
        Node(int k, int val): prev(NULL), next(NULL), key(k), value(val) {}
};

// Abstract class for cache
class Cache { 
    protected:
        int cap;
        Node *head;
        Node *tail;
        map<int,Node*> mp;
        virtual void set(int, int) = 0;
        virtual int get(int) = 0;
};

class LRUCache: public Cache {
    private:
        int count;
    public:
        //LRUCache(int capacity) : cap (capacity), head(NULL), tail(NULL) {}
        LRUCache(int capacity){
            cap = capacity;
            head = NULL;
            tail = NULL;
            count = 0;
        }
        void set (int key, int value) {
            if (mp[key] == 0) { // New key
                Node *node = new Node(key, value);
                
                if (count != 0) {
                    //cout << "check 1" << endl;
                    node->next = head;

                    // Update head
                    head->prev = node;
                    head = node;
                    count++;

                    // Update tail
                    if (count > cap){ // When capacity is reached
                        if (cap != 1) {
                            mp[tail->key] = 0;
                            tail = tail->prev;
                            tail->next = NULL;
                        }
                        else 
                            tail = head;
                        
                        count--;   
                    }
                }
                else { // First element
                    //cout << "check 2" << endl;
                    head = node;
                    tail = head;
                    count++;

                }
                mp[key] = node;
                
            }
            else { // Existing key
                Node *node = mp[key];
                
                if (node->prev != NULL) // Node not at head
                    node->prev->next = node->next;
                
                if (node->next != NULL) { // Node not at tail
                    if(node->prev != NULL)
                        node->next->prev = node->prev;
                }
                else 
                    tail = node->prev;

                if(node->prev != NULL) {
                    head->prev = node;
                    node->next = head;
                    node->prev = NULL;
                    node->value = value;
                    head = node;
                }
                else
                    node->value = value;
            }
        }
        int get(int key){
            if (mp[key] != 0)
                return mp[key]->value;
            else
                return -1;
        }
};

int main() {
    int n, capacity, i;
    cout << "Enter iterations: "; cin >> n;
    cout << "Enter cache capacity: "; cin >> capacity;
    //cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; ++i) {
        string command;
        cout << "Enter command: "; cin >> command;
        if (command == "get") {
            int key;
            cout << "Enter key: "; cin >> key;
            cout << "Value in key " << key << " is: " << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cout << "Enter key: "; cin >> key;
            cout << "Enter value: "; cin >> value;
            //cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
