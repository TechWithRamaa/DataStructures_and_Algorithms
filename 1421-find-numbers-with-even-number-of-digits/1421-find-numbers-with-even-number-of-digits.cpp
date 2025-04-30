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

    int findNumbers2(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            int length = 0;
            while (num > 0) {
                num /= 10;
                length++;
            }

            count += (length % 2 == 0) ? 1 : 0;
        }
        return count;
    }

    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if ((num >= 10 && num <= 99) 
            || (num >= 1000 && num <= 9999) 
            || num == 100000)
                count++;
        }
        return count;
    }
};