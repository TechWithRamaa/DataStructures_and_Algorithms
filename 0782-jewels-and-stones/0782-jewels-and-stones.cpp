class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelsSet(jewels.begin(), jewels.end());
        int count = 0;
        
        for(char c : stones) {
            if(jewelsSet.count(c)) {
                count++;
            }
        }
        
        return count;
    }
};