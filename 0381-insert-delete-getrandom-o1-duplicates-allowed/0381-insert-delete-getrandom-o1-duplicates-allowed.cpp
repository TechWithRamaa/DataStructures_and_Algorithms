class RandomizedCollection {
public:
    map<int, set<int>> m; // used to map element with the indices where it is
                          // present in vector v
    vector<int>
        elements; // used to store all the elements (contains duplicate as well)

    RandomizedCollection() {}

    bool insert(int val) {
        elements.push_back(val);
        m[val].insert(elements.size() - 1);

        return m[val].size() == 1;
    }

    bool remove(int val) {
        // Step 1: Check if val exists in the map
        if (m.find(val) == m.end()) {
            return false; // Nothing to remove
        }

        // Step 2: Get an index of 'val' from its set of indices
        int indexToRemove = *m[val].begin();

        // Step 3: Get the last element in the vector
        int lastElement = elements.back();
        int lastIndex = elements.size() - 1;

        // Step 4: Overwrite the element at indexToRemove with lastElement
        elements[indexToRemove] = lastElement;

        // Step 5: Update the map
        // Remove indexToRemove from val's index set
        m[val].erase(indexToRemove);

        // Update lastElement's index set:
        // Remove the old index (lastIndex) and insert the new one
        // (indexToRemove)
        m[lastElement].erase(lastIndex);
        if (indexToRemove != lastIndex) {
            m[lastElement].insert(indexToRemove);
        }

        // Step 6: Remove the last element from the vector
        elements.pop_back();

        // Step 7: If val has no more indices left, clean it up from the map
        if (m[val].empty()) {
            m.erase(val);
        }

        return true;
    }

    int getRandom() {
        return elements
            [rand() % elements.size()]; // rand() is used to get a random number
                                        // and it is % by v.size() so that the
                                        // result is within the size of vector v
    }
};