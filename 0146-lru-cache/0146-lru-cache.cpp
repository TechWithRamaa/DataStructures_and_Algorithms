class LRUCache1 {
public:
    LRUCache1(int capacity) { 
        this->capacity = capacity; 
    }

    int get(const int key) {
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

    void put(const int key, const int value) {
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

class LRUCache {
public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        Node *node = cache[key];
        moveToHead(node);
        return node->value; 
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node *node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            if(capacity == cache.size()) {
                Node *lru = removeTail();
                cache.erase(lru->key);
                delete lru;
            }

            Node *newNode = new Node(key, value);
            addToHead(newNode);
            cache[key] = newNode;
        }
    }

private:
    // DLL for maintaining the k, v pairs according to access order
    struct Node {
        int key, value;
        Node *next, *prev;

        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;
 
    
    void addToHead(Node *node) {
        node->next = head->next; 
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    Node* removeTail() {
        Node *lru = tail->prev;
        removeNode(lru);
        return lru;
    }
};