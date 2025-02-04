class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;

        for(auto &num : nums) {
            frequencyMap[num]++;
        }

        auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
        for(auto &entry:frequencyMap) {
            minHeap.push({entry.second, entry.first});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> topKElements;
        while(!minHeap.empty()) {
            topKElements.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return topKElements;
    }
};