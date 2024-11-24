class Solution {
public:
    int majorityElement(const vector<int>& nums) {
        return majorityElementByBoyerMooreVoting(nums);
    }
private:
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