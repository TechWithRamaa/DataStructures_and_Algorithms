class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        
        vector<int> result(N, -1);
        
        unordered_map<int, int> indexMap;
        for(int i = 0; i < N; i++) {
            indexMap[nums2[i]] = i;
        }
        
        for(int i = 0; i < N; i++) {
            result[i] = indexMap[nums1[i]];
        }
        
        return result;
    }
};