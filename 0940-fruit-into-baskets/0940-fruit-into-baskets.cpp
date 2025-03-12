class Solution {
public:
    // It s a beautiful experience solving this problem
    // This problem is nothing but the Longest subarray that contains at most k distinct characters
    
    // Dynamic Sliding Window
    int totalFruit(vector<int>& fruits) {
        int maxFruits = INT_MIN;

        unordered_map<int, int> fruitCount;
        int left = 0;
        for(int right = 0; right < fruits.size(); right++) {
            fruitCount[fruits[right]]++;

            if(fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;
                
                if(fruitCount[fruits[left]] == 0) {
                    fruitCount.erase(fruits[left]);
                }
                
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits == INT_MIN ? 0 : maxFruits;
    }
};