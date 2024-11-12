class Solution {
public:
    string getHint(const string secret, const string guess) {
        int bulls = 0, cows = 0;
        vector<int> secret_count(10, 0), guess_count(10, 0);

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bulls++;
            else {
                secret_count[secret[i] - '0']++;
                guess_count[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; i++) 
            cows += min(secret_count[i], guess_count[i]);
    
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};