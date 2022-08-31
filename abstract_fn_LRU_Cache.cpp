#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {
protected:
    map<int, Node*> mp;
    int cp;
    Node* tail;
    Node* head;
    virtual void set(int, int) = 0;
    virtual int get(int) = 0;
};

class LRUCache : public Cache {
    private:
        int count = 0;
    public:
    LRUCache(int capacity){
        cp = capacity;
        head = NULL;
        tail = NULL;
    }
    void set(int key, int value){     
        if(mp[key] == 0){          // New key
            Node *node = new Node(key,value);
            //cout << "Check size: " << mp.size() << endl;
            if (count != 0){
                node->next = head;
                head->prev = node;
                head = node;
                mp[key] = node;
                count++;
                if(count>cp){        // Capacity is reached
                    if (cp!=1) {
                        mp[tail->key] = 0;
                        tail = tail->prev;
                        tail->next = NULL;
                    }
                    else
                        tail = node;
                    
                    count--;
                }
            }
            else {                        // First element
                head = node;
                mp[key] = node;
                tail = head;
                count++;
            }
        }
        else{                         // Existing key
            Node *node = mp[key];
            if(node->prev != NULL)    // Node is not at head
                node->prev->next = node->next;
                    
            if(node->next != NULL)
                if(node->prev != NULL)
                    node->next->prev = node->prev;
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
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}