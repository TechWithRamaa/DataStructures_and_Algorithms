class Solution {
public:
   vector<int> grayCode(int n) {
        vector<int> result;  
        int size = 1 << n; // Total numbers in Gray Code sequence = 2^n
        
        for (int i = 0; i < size; ++i) {
            result.push_back(i ^ (i >> 1)); // Compute Gray Code using XOR
        }
        
        return result;
    }
};