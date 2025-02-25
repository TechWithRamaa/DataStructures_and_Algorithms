class Solution {
public:
    // Multiple approaches are there
    // Approach 1 - HashSet 
    // Approach 2 - HashMap
    // Approach 3 - XOR
    int singleNumber(vector<int>& nums) {
        int unique = 0;
        for (int num : nums) {
            unique ^= num; // XOR each number into unique
        }
        return unique;
    }
};