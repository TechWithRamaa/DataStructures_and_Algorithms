class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
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
};