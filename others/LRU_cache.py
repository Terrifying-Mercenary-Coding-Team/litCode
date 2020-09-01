from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.table = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.table:
            self.table.move_to_end(key,last=True)
            return self.table[key]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.table:
            self.table[key] = value
            self.table.move_to_end(key,last=True)
            return

        if len(self.table) == self.capacity:
            self.table.popitem(last=False)
        self.table[key] = value


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

if __name__ == "__main__":
    cache = LRUCache(2)
    print(cache.get(2))
    cache.put(2,6)
    print(cache.get(1))
    cache.put(1,5)
    cache.put(1,2)
    print(cache.get(1))
    print(cache.get(2))
    print(cache.table)
