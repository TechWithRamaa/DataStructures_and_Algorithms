class Solution {
public:
    // Approach 1 ~ BruteForce 
    int findKthPositive1(vector<int>& arr, int k) {
        int missingCount = 0, num = 1, i = 0;

        while (k > 0) {
            if (i < arr.size() && arr[i] == num) 
                i++; // Move to the next number in `arr`
             else 
                missingCount++; // Found a missing number
            

            if (missingCount == k)
                return num;

            num++; // Move to the next number
        }

        return -1; // Should never reach here
    }

    // Approach 2 ~ Missing Count -> Number Theory
    int findKthPositive(vector<int>& arr, int k) {

        for(int i = 0; i < arr.size(); i++) {
            int missingCount = arr[i] - ( i + 1); 

            if(missingCount >= k) {
                return i + k;
            }
        }

        return arr.size() + k;
    }
};