class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
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
};