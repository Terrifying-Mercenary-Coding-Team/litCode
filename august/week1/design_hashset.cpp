#include <bits/stdc++.h>

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<bool> container;
    MyHashSet() {
        container.resize(1000001);
    }
    
    void add(int key) {
        container[key] = true;
    }
    
    void remove(int key) {
        if(container[key])   container[key] = false; 
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(container[key])  return true;
        else    return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(){
    MyHashSet hashSet;
    hashSet.add(1);         
    hashSet.add(2);         
    cout << hashSet.contains(1) << endl;   // returns true
    cout << hashSet.contains(3) << endl;    // returns false (not found)
    hashSet.add(2);          
    cout << hashSet.contains(2) << endl;    // returns true
    hashSet.remove(2);          
    cout << hashSet.contains(2) << endl;    // returns false (already removed)
}
