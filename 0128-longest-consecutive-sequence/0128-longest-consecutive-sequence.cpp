class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int longestSeq = 0;

        for(int element: seen) {
            // previous element should not be there
            // then current element is the start of the sequence
            if(!seen.count(element - 1)) {
                int currentLong = 1;
                int currentElement = element;

                // next element should be there
                // extend the sequence as long as possible
                while(seen.count(currentElement + 1)) {
                    currentLong += 1;
                    currentElement += 1;
                }

                longestSeq = max(longestSeq, currentLong);
            }
        }

        return longestSeq;
    }
};