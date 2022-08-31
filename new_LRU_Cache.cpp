#include<iostream>
#include<string>
#include <map>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

class Cache {
    public:
        int capacity;
        map<int,int> map_;
        virtual void set(int, int) = 0;
        virtual int get(int) = 0;
};

class LRU_Cache : public Cache {
    private:
        unordered_set<int> lru_;
    public:
        LRU_Cache(int cap) {
            capacity = cap;
        }
        void set(int addr, int data) {
            if (lru_.size() < capacity) {
                if (lru_.find(addr) == lru_.end()) {
                    lru_.insert(addr);
                }
                else {
                    lru_.erase(addr);
                    lru_.insert(addr);
                }
            }
            else {
                unordered_set<int>::iterator it = lru_.begin();
                int remove_addr=0;
                while(it != lru_.end()) {
                    remove_addr = *it;
                    it++;
                }
                lru_.erase(remove_addr);
                lru_.insert(addr);
                map_.erase(remove_addr);
                           
            }
            map_[addr] = data; 
        }
        int get(int addr) {
            if (map_.find(addr) != map_.end()) {
                lru_.erase(addr);
                lru_.insert(addr);
            }
            else { 
                map_[addr] = 1 + rand()%1024; // Emulating getting from memory
                if (lru_.size() < capacity) 
                    lru_.insert(addr);                
                else {
                    unordered_set<int>::iterator it = lru_.begin();
                    int remove_addr=0;
                    while(it != lru_.end()) {
                        remove_addr = *it;
                        it++;
                    }
                    lru_.erase(remove_addr);
                    lru_.insert(addr);
                    map_.erase(remove_addr);
                }
            }
            return map_[addr];
        }
};

int main() {
    int n, capacity, i;
    cout << "Enter iterations: "; cin >> n;
    cout << "Enter cache capacity: "; cin >> capacity;
    //cin >> n >> capacity;
    Cache *lru_cache;
    lru_cache = new LRU_Cache(capacity);
    //LRU_Cache l(capacity);
    for (i = 0; i < n; ++i) {
        string command;
        cout << "Enter command: "; cin >> command;
        if (command == "get") {
            int key;
            cout << "Enter key: "; cin >> key;
            cout << "Value in key " << key << " is: " << lru_cache->get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cout << "Enter key: "; cin >> key;
            cout << "Enter value: "; cin >> value;
            //cin >> key >> value;
            lru_cache->set(key, value);
        }
    }
    return 0;
}