#include<iostream>
#include<string>
#include <map>
#include <unordered_set>
#include <list>
#include <stdlib.h>

using namespace std;


class Cache {
    public:
        int capacity;
        map<int,int> cache_;
        virtual void set (int, int) = 0;
        virtual int get (int) = 0;
};

class LRU_Cache : public Cache{
    private:
        list<int> lru_;
    public:
        LRU_Cache(int cap) {
            capacity = cap;
        }
        void set (int addr, int data) {
            if (cache_.size() < capacity) {
                if (cache_.find(addr) != cache_.end()) {
                   lru_.remove(addr);
                }
                cache_[addr] = data;
                lru_.push_back(addr);
            }            
            else {
                if (cache_.find(addr) != cache_.end()) {
                    lru_.remove(addr);
                }
                else {
                    int adr_rem = lru_.front();
                    cache_.erase(adr_rem);
                    lru_.pop_front();
                }
                lru_.push_back(addr);
                cache_[addr] = data;
            }
        }
        int get (int addr) {
            if (cache_.find(addr) != cache_.end()) {
                lru_.remove(addr);
                lru_.push_back(addr);
                return cache_[addr];
            }
            else {
                cache_[addr] = 1 + rand()%1024; // Emulating getting from memory
                if (cache_.size() < capacity) {
                    lru_.push_back(addr);
                }
                else {
                    int adr_rem = lru_.front();
                    cache_.erase(adr_rem);
                    lru_.pop_front();
                    lru_.push_back(addr);

                }
                return cache_[addr];
            }

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