#include <iostream>

using namespace std;

#define MAX 1000000

bool hash_set[MAX+1];

class MyHashSet {
public:
	/** Initialize your data structure here. */
	MyHashSet() {
		for (int i = 0; i < MAX + 1; i++) hash_set[i] = false;
	}

	void add(int key) {
		hash_set[key] = true;
	}

	void remove(int key) {
		hash_set[key] = false;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		return hash_set[key];
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main()
{
	MyHashSet hashSet;
	hashSet.add(1);
	hashSet.add(2);
	cout<<hashSet.contains(1)<<endl;    // returns true
	cout<<hashSet.contains(3)<<endl;    // returns false (not found)
	hashSet.add(2);
	cout<<hashSet.contains(2)<<endl;    // returns true
	hashSet.remove(2);
	cout<<hashSet.contains(2)<<endl;    // returns false (already removed)
}