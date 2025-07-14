class Solution {
public:
    /*
    We want to avoid placing the same characters next to each other.
    So, we should always try to place the character with the highest remaining frequency, 
    then the next highest, and alternate.

    This naturally leads us to a Greedy + Max-Heap strategy.
    */
    string reorganizeString(string s) {
        unordered_map<char, int> freqMap;
        
        for(const auto& ch : s) {
            freqMap[ch]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for(const auto& [key, count] : freqMap) {
            maxHeap.push({count, key});
        }

        string result = "";
        while(maxHeap.size() >= 2) {
            auto [count1, key1] = maxHeap.top(); 
            maxHeap.pop();

            auto [count2, key2] = maxHeap.top();
            maxHeap.pop();

            result += key1;
            result += key2;

            if(--count1 > 0)
                maxHeap.push({count1, key1});

            if(--count2 > 0)
                maxHeap.push({count2, key2});
        }

        if(!maxHeap.empty()) {
            if(maxHeap.top().first > 1) 
                return ""; // not possible for repeatable characters
            
            result += maxHeap.top().second;
        }

        return result;
    }   
};