class NumArray {
private:
    vector<int> array;
    vector<int> prefixSum;

    void preCompute() {
        prefixSum[0] = 0;

        for(int i = 0; i < array.size(); i++) {
            prefixSum[i+1] = prefixSum[i] + array[i];
        }

    }
public:
    NumArray(vector<int>& nums) {
        array = nums;
        prefixSum.resize(nums.size() + 1, 0);

        preCompute();
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */