class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXOR(n);
        prefixXOR[0] = arr[0];

        // Compute the prefix XOR array
        for (int i = 1; i < n; ++i) 
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
        

        vector<int> result;
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            if (left == 0) 
                result.push_back(prefixXOR[right]);
             else 
                result.push_back(prefixXOR[right] ^ prefixXOR[left - 1]);
            
        }

        return result;
    }
};