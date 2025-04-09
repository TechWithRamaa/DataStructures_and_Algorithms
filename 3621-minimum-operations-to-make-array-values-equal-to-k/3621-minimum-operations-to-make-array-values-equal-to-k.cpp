class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> uniqueElements;

        for(auto num : nums) {
            if(num < k) 
                return -1;
            
            if(num == k)
                continue;

            uniqueElements.insert(num); 
        }

        return uniqueElements.size();
    }
};