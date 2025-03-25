class Solution {
public:
    // Approach 1 
    // Optimized
    // Technique - Palindrome Character Frequency Property

    /*

    Pseudocode:

        Count character frequencies using a hashmap or set.

        Count how many characters have an odd frequency.

        Check the conditions:

            If more than one character has an odd count → Return false.

            Otherwise → Return true.
    */
    bool canPermutePalindrome(string s) {
        unordered_set<char> oddFreqCount;

        for(auto ch : s) {
            if(oddFreqCount.count(ch)) 
                oddFreqCount.erase(ch);
            else 
                oddFreqCount.insert(ch);
        }

        return oddFreqCount.size() <= 1;
    }
};