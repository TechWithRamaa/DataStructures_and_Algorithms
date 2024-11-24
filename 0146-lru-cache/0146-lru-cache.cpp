class LRUCache {
public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (map.find(key) == map.end())
            return -1; 
            
        // Move the accessed pair to the front of the list
        auto it = map[key];
        int value = it->second;
        dll.erase(it);
        dll.push_front({key, value});
        map[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        // If the key already exists, remove it
        if (map.find(key) != map.end()) 
            dll.erase(map[key]);
        
        // If the dll is at full capacity, evict the least recently used item
        if (dll.size() == capacity) {
            auto lru = dll.back();
            map.erase(lru.first);
            dll.pop_back();
        }

        // Insert the new key-value pair at the front
        dll.push_front({key, value});
        map[key] = dll.begin();
    }

private:
    int capacity;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */