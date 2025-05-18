class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> complementMap;
        int noOfPairs = 0;

        for(auto t : time) {
            int r = t % 60;
            int complement = (60 - r) % 60;

            if(complementMap.count(complement)) 
                noOfPairs += complementMap[complement]; 

            complementMap[r]++;
        }

        return noOfPairs;
    }
};