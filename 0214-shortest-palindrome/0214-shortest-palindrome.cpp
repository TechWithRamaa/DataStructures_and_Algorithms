class Solution {
private:
    // Function to compute LPS array
    vector<int> computeLPS(string str) {
        int n = str.size();
        vector<int> lps(n, 0);

        int len = 0; // longest prefix which is also suffix
        for (int i = 1; i < n;) {
            if (str[i] == str[len]) {
                lps[i] = ++len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // fallback
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        string combined = s + "#" + rev_s;
        vector<int> lps = computeLPS(combined);

        int longestPalindromicPrefix = lps.back();

        string suffixToAdd = rev_s.substr(0, s.size() - longestPalindromicPrefix);
        //cout << suffixToAdd << " - " << s.size() - longestPalindromicPrefix;
        return suffixToAdd + s;
    }
};

/*
Shortest Palindrome using KMP – Quick Summary
Goal: Make the shortest palindrome by adding characters in front of a given string s.
Key idea: Find the longest palindromic prefix of s.

How?
    Reverse the string → rev_s.
    Create a combined string → s + '#' + rev_s.
    Build the LPS array for this combined string.
    LPS last value gives the length of the longest palindromic prefix in s.

Answer: Add the remaining suffix (from rev_s) in front of s.

Example:
s = "aacecaaa" → LPS end = 7 → Add "a" → Result = "aaacecaaa"

*/