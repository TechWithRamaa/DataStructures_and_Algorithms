class Solution {
private:
    bool isVowel(char c) {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
    void findNextConsonant(string& word, vector<int>& next_consonant) {
        int n = word.size();
        int next = n;
        for (int i = n - 1; i >= 0; --i) {
            next_consonant[i] = next;
            if (!isVowel(word[i]))
                next = i;
        }
    }

public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int> next_consonant(n);
        findNextConsonant(word, next_consonant);

        long long count = 0;
        int consonants = 0;
        unordered_map<char, int> vowel_freq;
        int left = 0;
        int right = 0;
        int prev = -1;
        while (right < n) {
            if (prev != right) {
                if (isVowel(word[right]))
                    vowel_freq[word[right]]++;
                else
                    consonants++;
                prev = right;
            }

            if (right >= (5 + k - 1)) {
                if (vowel_freq.size() == 5 and consonants == k)
                    count += next_consonant[right] - right;

                // Move left ptr to right: Shrink window
                if ((vowel_freq.size() == 5 and consonants == k) or
                    (consonants > k)) {
                    if (isVowel(word[left])) {
                        vowel_freq[word[left]]--;
                        if (vowel_freq[word[left]] == 0)
                            vowel_freq.erase(word[left]);
                    } else
                        consonants--;
                    left++; // Shrink window
                } else
                    right++; // Expand window
            } else
                right++; // Insufficient window size, hence expand
        }
        return count;
    }
};