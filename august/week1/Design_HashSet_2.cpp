#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

class MyHashSet {
	bool arr[1000001];
public:
	/** Initialize your data structure here. */
	MyHashSet() {
		for (int i = 0; i < 1000001; i++)
			arr[i] = false;
	}

	void add(int key) {
		arr[key] = true;
	}

	void remove(int key) {
		arr[key] = false;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		return arr[key];
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(void)
{
	MyHashSet hashSet = MyHashSet();
	hashSet.add(1);
	hashSet.add(2);
	hashSet.contains(1);    // returns true
	hashSet.contains(3);    // returns false (not found)
	hashSet.add(2);
	hashSet.contains(2);    // returns true
	hashSet.remove(2);
	hashSet.contains(2);    // returns false (already removed)
	return 0;
}