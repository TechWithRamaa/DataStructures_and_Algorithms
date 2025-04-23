class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> hashMap;
        int maxValue = 0;

        for (int i = 1; i <= n; ++i) {
            int key = 0, i0 = i;

            while (i0) {
                key += i0 % 10;
                i0 /= 10;
            }

            hashMap[key]++;
            maxValue = max(maxValue, hashMap[key]);
        }

        int count = 0;

        for (auto& [_, value] : hashMap) {
            if (value == maxValue) {
                count++;
            }
        }

        return count;
    }
};