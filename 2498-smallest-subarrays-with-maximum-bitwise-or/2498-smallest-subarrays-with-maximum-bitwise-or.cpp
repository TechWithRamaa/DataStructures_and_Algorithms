class Solution {
public:
    // OR is monotonic
    vector<int> smallestSubarrays(vector<int>& nums) {
        int N = nums.size();

        vector<int> ans(N);
        vector<int> lastSeen(32, -1);

        for (int i = N - 1; i >= 0; i--) {

            // Update lastSeen for bits set in nums[i]
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b)) {
                    lastSeen[b] = i;
                }
            }

            // Find the furthest right index needed to get max OR
            int furthest = i;
            
            for (int b = 0; b < 32; ++b) {
                if (lastSeen[b] != -1) {
                    furthest = max(furthest, lastSeen[b]);
                }
            }

            ans[i] = furthest - i + 1;
        }

        return ans;
    }
};

/*
    We process the array in reverse because OR is monotonic and only grows.
    I track the latest index each bit appears and compute the furthest index
    needed to achieve the full OR. This gives me the minimal subarray size
    required to hit the OR target starting from each index.
*/