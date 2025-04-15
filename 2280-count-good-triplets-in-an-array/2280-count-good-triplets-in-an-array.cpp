class BIT {
    vector<int> tree;
public:
    BIT(int n) : tree(n + 2, 0) {}

    void update(int i, int delta) {
        for (++i; i < tree.size(); i += i & -i)
            tree[i] += delta;
    }

    int query(int i) { // sum from 0 to i
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += tree[i];
        return res;
    }

    int range(int l, int r) { // sum from l to r
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        
        // Step 1: Build position map from nums2
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i;

        // Step 2: Convert nums1 to mapped index array
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i)
            mapped[i] = pos[nums1[i]];

        // Step 3: Count of smaller elements before current (left of j)
        BIT leftBIT(n), rightBIT(n);
        vector<int> left(n, 0), right(n, 0);

        // Fill rightBIT with all mapped values
        for (int val : mapped)
            rightBIT.update(val, 1);

        long long res = 0;

        for (int j = 0; j < n; ++j) {
            int val = mapped[j];

            // Remove current from rightBIT (as we now process it)
            rightBIT.update(val, -1);

            // Count of elements to the left of j that are less than val
            int leftCount = leftBIT.query(val - 1);

            // Count of elements to the right of j that are greater than val
            int rightCount = rightBIT.range(val + 1, n);

            // Triplets centered at j
            res += 1LL * leftCount * rightCount;

            // Mark val as seen in leftBIT
            leftBIT.update(val, 1);
        }

        return res;
    }
};
