class Solution {
public:
    // Greedy + Stack .. 
    // I mistaken to be Dynamic Programming oops
    int maximumGain(auto& s, int x, int y) {
        int totalScore = 0;

        if(x > y) {
            totalScore += removePattern(s, 'a', 'b', x); // Remove "ab" first
            totalScore += removePattern(s, 'b', 'a', y); // Then remove "ba"
        } else {
            totalScore += removePattern(s, 'b', 'a', y); // Remove "ba" first
            totalScore += removePattern(s, 'a', 'b', x); // Then remove "ab"
        }

        return totalScore;
    }

private:
    int removePattern(string &s, char first, char second, int score) {
        string stack; // clever way of using string as stack so that it can be assigned back to the string
        int total = 0;

        for(const auto& ch : s) {
            if(!stack.empty() && stack.back() == first & ch == second) {
                stack.pop_back();
                total += score;
            } else {
                stack.push_back(ch);
            }
        }

        s = stack; 
        return total;
    }
};