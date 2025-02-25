class Solution {
public:
    // Hashset Approach ~ O ( n )
    bool containsDuplicateApproach1(vector<int>& nums) {
        unordered_set<int> set;

        for(auto num: nums){
            if(set.find(num) != set.end()) {
                return true;
            }
            set.insert(num);
        }
        return false;
    }

    // Sorting
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};