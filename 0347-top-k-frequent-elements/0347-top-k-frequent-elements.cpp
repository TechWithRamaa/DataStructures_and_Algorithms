class Solution {
public:
    // Frequency Map + Min Heap ~ O(n) + O(n log k) + O(k)
    vector<int> topKFrequentMinHeap(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        
        for(auto num : nums) {
            freqMap[num]++;
        }
        
        // {frequency, num} - minHeap - keep removing the lowest frequency element
        // at the end, minHeap will contain the top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
        
        for(auto [num, freq] : freqMap) {
            pq.push({freq, num});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> result;
        while(!pq.empty()) {
            auto [freq, num] = pq.top();
            pq.pop();
            result.push_back(num);
        }
        
        return result;
    }
    
    // Frequence Map + Bucket Sort ~ O(n) + O(n) + O(k)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        
        for(auto num : nums) {
            freqMap[num]++;
        }
        
        vector<vector<int>> bucket(nums.size() + 1);
        
        for(auto [num, freq] : freqMap) {
            bucket[freq].push_back(num);
        }
        
        vector<int> result;
        for(int i = nums.size(); i >= 0; i--) {
            for(int num : bucket[i]) {
                result.push_back(num);
            }
            
             if(result.size() == k) 
                break;
        }
        
        return result;
    }
};