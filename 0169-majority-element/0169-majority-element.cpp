class Solution {
public:
    int majorityElement(const vector<int>& nums) {
        // return majorityElementByBoyerMooreVoting(nums);
        return majorityElementByHashing(nums);
    }

private:
    // BruteForce
    // TC - O(n); SC - O(n)
    int majorityElementByHashing(const vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        const int N = nums.size();

        for (const int& num : nums) {
            frequencyMap[num] += 1;

            // VERIFICATION
            if (frequencyMap[num] > N / 2)
                return num;
        }

        return -1;
    }

    // Algorithmic approach
    // BoyerMooreVoting
    // TC - O(n); SC - O(1)
    int majorityElementByBoyerMooreVoting(const vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0)
                candidate = num;

            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};