#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    vector<int> clock;
    unordered_map<int,int> hash;
    int size;

    LRUCache(int capacity) : size(capacity) {}
    
    int get(int key) {
        auto it = find(clock.begin(),clock.end(),key);
        if(it==clock.end())  return -1;
        int ret=hash[key];
        clock.erase(it);
        clock.push_back(key);

        return ret;
    }
    
    void put(int key, int value) {
        auto it = find(clock.begin(),clock.end(),key);
        if(it!=clock.end()){
            hash[key] = value;
            clock.erase(it);
            clock.push_back(key);
            return;
        }
        if(clock.size()==size){
            clock.erase(clock.begin());
            hash[key] = value;
            clock.push_back(key);
        }
        else{
            hash[key] = value;
            clock.push_back(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
