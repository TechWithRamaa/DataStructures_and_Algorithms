class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>&b) {
            return a[1] < b[1]; 
        });

        int maxLength = 0;
        int currentEnd = INT_MIN;
        const int N = pairs.size(); 

        for(int i = 0; i < N; i++) {
            vector<int>& pair = pairs[i];
            if(pair[0] > currentEnd) {
                maxLength += 1;
                currentEnd = pair[1];
            }
        }

        return maxLength;
    }
};