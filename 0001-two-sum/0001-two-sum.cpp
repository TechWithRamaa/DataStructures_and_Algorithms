class Solution {
public:
    // Complement is the core piece here
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complementIndexMap;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(complementIndexMap.find(complement) != complementIndexMap.end()) {
                return {complementIndexMap[complement], i};
            } else {
            complementIndexMap[nums[i]] = i;
            }
        }

        return {};
    }
};