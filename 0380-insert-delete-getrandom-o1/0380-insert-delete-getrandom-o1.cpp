class RandomizedSet {
private:
    vector<int> elements;
    unordered_map<int, int> indexMap; // {key, value} is {element -> index }
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(indexMap.find(val) != indexMap.end()) {
            return false;
        }

        elements.push_back(val);
        int lastIndex = elements.size() - 1;
        indexMap[val] = lastIndex;
        return true;
    }
    
    bool remove(int val) {
        if(indexMap.find(val) == indexMap.end()) {
            return false;
        }

        int eleIndex = indexMap[val];
        int lastElement = elements.back();

        elements[eleIndex] = lastElement;
        elements.pop_back();

        indexMap[lastElement] = eleIndex;
        indexMap.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % elements.size();
        return elements[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */