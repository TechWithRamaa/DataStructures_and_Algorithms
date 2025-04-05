class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orAll = 0;
        for (int num : nums) {
            orAll |= num;
        }
        return orAll * (1 << (nums.size() - 1));
    }
};