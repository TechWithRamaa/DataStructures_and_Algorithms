class Solution {
public:
    // Approach 1
    bool threeConsecutiveOdds1(vector<int>& arr) {
        int countOfOdds = 0;

        for(auto num : arr) {
            if((num % 2) != 0) {
                countOfOdds++;

                if(countOfOdds == 3)
                    return true;
                else
                    continue;  
            }

            countOfOdds = 0; // reset to zero
        }

        return false;
    }

    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        // Loop through the array up to the third-to-last element
        for (int i = 0; i < n - 2; i++) {
            // Check if the current element and the next two elements are all
            // odd
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
};