class Solution {
public:
    int findNumbers1(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (to_string(num).length() % 2 == 0)
                count++;
        }
        return count;
    }

    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            int length = 0;
            while(num > 0) {
                num /= 10;
                length++;
            }

            count += (length % 2 == 0) ? 1 : 0;
        }
        return count;
    }
};