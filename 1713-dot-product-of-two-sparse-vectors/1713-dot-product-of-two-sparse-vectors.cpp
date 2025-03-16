class SparseVector {

public:
    vector<pair<int, int>> nonZeroVector;

    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nonZeroVector.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i = 0, j = 0, dotProduct = 0;
        long long result = 0; // Use long long for safety

        while(i < nonZeroVector.size() && j < vec.nonZeroVector.size()) {
            if(nonZeroVector[i].first == vec.nonZeroVector[j].first) {
                dotProduct += nonZeroVector[i].second * vec.nonZeroVector[j].second;
                i++;
                j++;
            } else if (nonZeroVector[i].first < vec.nonZeroVector[j].first) {
                i++;
            } else {
                j++;
            }
        }

        return dotProduct;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);