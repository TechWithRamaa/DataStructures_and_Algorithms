class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;

        sort(arr.begin(), arr.end());
        int minAbsDiff = INT_MAX;

        for(int i = 1; i < arr.size(); i++) {
            int absDiff = abs(arr[i] - arr[i - 1]);
            
            if(absDiff <= minAbsDiff) {
                minAbsDiff = absDiff;
            }
        }

         for(int i = 1; i < arr.size(); i++) {
            int absDiff = abs(arr[i] - arr[i - 1]);
            
            if(absDiff == minAbsDiff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }

        return result;
    }
};