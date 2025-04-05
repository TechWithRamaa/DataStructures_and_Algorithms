class NumArray {
private:
    vector<int> tree; // segment tree
    int n;

    void buildTree(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(nums, 2 * node, start, mid);
            buildTree(nums, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                updateTree(2 * node, start, mid, idx, val);
            else
                updateTree(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int queryTree(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0; // No overlap
        }
        if (L <= start && end <= R) {
            return tree[node]; // Total overlap
        }
        int mid = (start + end) / 2;
        int leftSum = queryTree(2 * node, start, mid, L, R);
        int rightSum = queryTree(2 * node + 1, mid + 1, end, L, R);
        return leftSum + rightSum; // Partial overlap
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n); // Segment tree size
        buildTree(nums, 1, 0, n - 1);
    }

    void update(int index, int val) {
        updateTree(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return queryTree(1, 0, n - 1, left, right);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */