class Solution {
public:
    // Reframe the problem into maintain a fixed window of 1
    // find the minimum zeros present in a window 
    // that would give the minimum swaps required
    // Fixed Sliding Window
    int minSwaps(vector<int>& data) {
        int countOnes = 0;

        for(auto num : data) {
            if(num == 1)    
                countOnes++;
        }

        int countZeroes = 0;
        for(int i = 0; i < countOnes; i++) {
            if(data[i] == 0) 
                countZeroes++;
        }

        int minimumSwaps = countZeroes;
        for(int i = countOnes; i < data.size(); i++) {
            // outgoing element
            if(data[i - countOnes] == 0)
                countZeroes--;

            // incoming element
            if(data[i] == 0) 
                countZeroes++;

            minimumSwaps = min(minimumSwaps, countZeroes);
        }

        return minimumSwaps;
    }
};