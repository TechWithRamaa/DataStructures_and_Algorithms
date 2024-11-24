class Solution {
public:
    int majorityElement(const vector<int>& nums) {
        return majorityElementByBoyerMooreVoting(nums);
    }

private:
    int majorityElementByHashing(const vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        const int N = nums.size();

        for (const int& num : nums) {
            frequencyMap[num] += 1;

            if (frequencyMap[num] > N / 2)
                return num;
        }

        return -1;
    }

    int majorityElementByBoyerMooreVoting(const vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (const int& num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num != candidate)
                count--;
            else if (num == candidate)
                count++;
        }

        return candidate;
    }
};