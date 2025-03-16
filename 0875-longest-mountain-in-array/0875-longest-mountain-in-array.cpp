class Solution {
public:
    // Greedy Approach
    // Natural instinctive problem solving
    // solution involves 1 pass 2 steps
    // find peak, followed by expansion outwards in both directions
    int longestMountain(vector<int>& arr) {
        int N = arr.size();

        if(N < 3) {
            return 0;
        }

        int maxLen = 0;

        // pay attention to boundaries
        for(int i = 1; i < N - 1; i++) {
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                // peak found at i
                // expand the mountain

                // expanding left side
                int left = i - 1;
                while(left > 0 && arr[left] > arr[left - 1]){
                    left--;
                }

                // expanding right side
                int right = i + 1;
                while(right < N - 1 && arr[right] > arr[right + 1]){
                    right++;
                }

                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};