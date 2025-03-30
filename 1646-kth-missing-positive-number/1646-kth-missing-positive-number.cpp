class Solution {
public:
    // Approach 1 ~ BruteForce
    // TC ~ O ( N ) 
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
    // TC ~ O ( N )
    int findKthPositive2(vector<int>& arr, int k) {

        for(int i = 0; i < arr.size(); i++) {
            int missingCount = arr[i] - ( i + 1); 

            if(missingCount >= k) {
                return i + k;
            }
        }

        return arr.size() + k;
    }

    // Approach 3 ~ Binary Search
    // TC ~ O ( log N )
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            int missingCount = arr[mid] - (mid + 1);

            if(missingCount < k) 
                left = mid + 1;
            else 
                right = mid - 1;
        }

        return k + left;
    }
};