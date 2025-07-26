class Solution {
    /*
    The approach ensures the sequence has only two unique values, 
    and those two differ by exactly 1 — which makes the difference between the max and min exactly 1.

    Thus, the condition is guaranteed by:

    Comparing num and num + 1 only
    Not including any third number

    */
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        int longest = 0;
        for (auto& [num, count] : freq) {
            if (freq.count(num + 1)) {
                longest = max(longest, count + freq[num + 1]);
            }
        }
        return longest;
    }
};