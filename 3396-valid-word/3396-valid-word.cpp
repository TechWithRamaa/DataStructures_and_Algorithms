class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3)
            return false;

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        bool atleastOneConsonant = false, atleastOneVowel = false;

        for(auto& ch : word) {
            if(ch >= '0' && ch <= '9') {
                cout << "digit - " << ch << endl;
                continue;
            } 
            else if(vowels.count(ch) > 0 || (isupper(ch) && vowels.count(tolower(ch)) > 0)) {
                cout << "vowel - " << ch << endl;
                atleastOneVowel = true;
            }
            else if(!isalnum(ch)){
                cout << ch << "endl";
                return false;
            }
            else if(!atleastOneConsonant) {
                cout << "consonant - " << ch << endl;
                atleastOneConsonant = true;
            } 
        }

        return atleastOneVowel && atleastOneConsonant;
    }
};