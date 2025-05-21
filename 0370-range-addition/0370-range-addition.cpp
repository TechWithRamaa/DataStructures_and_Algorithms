class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diffArray(length, 0);

        for(auto& update : updates) {
            int left = update[0];
            int right = update[1];
            int value = update[2];

            diffArray[left] += value;

            if(right + 1 < length)
                diffArray[right + 1] -= value;
        }

        for(int i = 1; i < length; i++) {
            diffArray[i] += diffArray[i-1];
        }

        return diffArray;
    }
};