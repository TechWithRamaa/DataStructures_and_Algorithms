class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3)
            return false;

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        bool hasVowel = false, hasConsonant = false;

        for(auto& ch : word) {
            if (isdigit(ch)) 
                continue;
            if (!isalnum(ch)) 
                return false;
            
            char lowerCh = tolower(ch);
            if (vowels.count(lowerCh)) 
                hasVowel = true;
            else 
                hasConsonant = true;
        }

        return hasVowel && hasConsonant;
    }
};