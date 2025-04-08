class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;

        while (true) {
            unordered_set<int> duplicates;
            bool duplicateFound = false;

            for (auto num : nums) {
                if (duplicates.count(num)) {
                    duplicateFound = true;
                    break;
                }
                duplicates.insert(num);
            }

            if (!duplicateFound)
                break;

            if (nums.size() <= 3)
                nums.clear();
            else
                nums.erase(nums.begin(), nums.begin() + 3);

            ops++;
        }

        return ops;
    }
};