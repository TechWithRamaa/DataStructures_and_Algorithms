class Solution {
public:
    // ~ O(n log k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap;
        
        for(auto num : nums) {
            minHeap.push(num);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
};