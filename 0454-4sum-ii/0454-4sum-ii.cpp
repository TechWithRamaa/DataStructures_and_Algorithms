class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                     vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int, int> sumAB;
        int count = 0;

        // Step 1: Store all possible sums of A and B
        for (int a : nums1) {
            for (int b : nums2) {
                sumAB[a + b]++;
            }
        }

        // Step 2: Find complementary sums in C and D
        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);
                if (sumAB.find(target) != sumAB.end()) {
                    count += sumAB[target]; // Add the frequency
                }
            }
        }

        return count;
    }
};