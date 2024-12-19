class LFUCache {

    private:
        int capacity;
        int minFreq; // Tracks the minimum frequency in the cache
        unordered_map<int, pair<int, int>>  keyValueFreq; // key -> {value, frequency}
        unordered_map<int, list<int>> freqList; // frequency -> list of keys
        unordered_map<int, list<int>::iterator> keyIter; // key -> iterator to the key's position in freqList

        void updateFrequency(int key) {
            int freq = keyValueFreq[key].second;
            freqList[freq].erase(keyIter[key]); // Remove key from its current frequency list
            
            if (freqList[freq].empty()) {
                freqList.erase(freq);
                
                if (minFreq == freq)
                    minFreq++; // Update minFreq if needed
            }
            freq++;
            keyValueFreq[key].second = freq; // Update the frequency of the key
            freqList[freq].push_back(key); // Add key to the new frequency list
            keyIter[key] = --freqList[freq].end(); // Update key's iterator
        }

    public:
        LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

        int get(int key) {
            if (keyValueFreq.find(key) == keyValueFreq.end())
                return -1; // Key not found
            
            updateFrequency(key);
            return keyValueFreq[key].first; // Return the value of the key
        }

        void put(int key, int value) {
            if (capacity == 0)
                return;

            if (keyValueFreq.find(key) != keyValueFreq.end()) {
                // Key exists: Update value and frequency
                keyValueFreq[key].first = value;
                updateFrequency(key);
            } else {
                // Key doesn't exist: Insert new key
                if (keyValueFreq.size() >= capacity) {
                    // Remove the least frequently used key
                    int keyToRemove = freqList[minFreq].front();
                    freqList[minFreq].pop_front();
                    
                    if (freqList[minFreq].empty())
                        freqList.erase(minFreq);
                    
                    keyValueFreq.erase(keyToRemove);
                    keyIter.erase(keyToRemove);
                }
                // Insert the new key
                keyValueFreq[key] = {value, 1};
                freqList[1].push_back(key);
                keyIter[key] = --freqList[1].end();
                minFreq = 1; // Reset minFreq to 1
            }
        }
    };

    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */