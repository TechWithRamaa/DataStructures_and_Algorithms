// Approach 1 
// Choosing Data Structure for storing the sparse vector is the key problem here 
// We can use vector<pair<int, int>> for storing sparse vector efficiently (less space)
// best suited when both the vectors are sparse
class SparseVector1 {

public:
    vector<pair<int, int>> nonZeroVector;

    SparseVector1(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nonZeroVector.push_back({i, nums[i]});
            }
        }
    }
    
    // TC ~ O ( n + m ) for vector<pair<int, int>>
    int dotProduct(SparseVector1& vec) {
        int i = 0, j = 0, dotProduct = 0;
    
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


// Approach 2 
// Choosing Data Structure for storing the sparse vector is the key problem here 
// We can use unordered_map<int, int> for storing sparse vector efficiently (less space)
// best suited when only 1 vector is sparse
class SparseVector {

public: 
    unordered_map<int, int> nonZeroMap;

    SparseVector(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nonZeroMap[i] = nums[i];
            }
        }
    }

    // TC ~ O ( min (m, n) )
    // Best suited when only 1 vector is sparse
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for(auto [key, value] : nonZeroMap) {
            if(vec.nonZeroMap.count(key) > 0) {
                result += nonZeroMap[key] * vec.nonZeroMap[key];
            }
        }

        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);