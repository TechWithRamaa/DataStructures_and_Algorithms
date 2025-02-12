class Solution {
public:
    string countAndSay(int n) {
       // Base case: the first term is always "1"
        if (n == 1) {
            return "1";
        }
        
        // Recursive case: get the previous term
        string prevTerm = countAndSay(n - 1);
        
        // Now generate the current term from the previous term
        string currentTerm = "";
        int count = 1;
        
        for (int i = 1; i < prevTerm.length(); i++) {
            // If the current digit is the same as the previous one, increase the count
            if (prevTerm[i] == prevTerm[i - 1]) {
                count++;
            } else {
                // Otherwise, add the count and the previous digit to the result
                currentTerm += to_string(count) + prevTerm[i - 1];
                count = 1; // Reset count for the new digit
            }
        }
        
        // Don't forget to add the last group of characters
        currentTerm += to_string(count) + prevTerm[prevTerm.length() - 1];
        
        return currentTerm;
    }
};