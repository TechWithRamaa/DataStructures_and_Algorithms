class Solution {
public:
    /*
    Greedy + Stack Approach
    
    Traverse the string character by character.
    Use a stack to keep track of (character, count):
        If the current character is the same as the stack’s top character, increment its count.
        If the count becomes k, pop it from the stack (remove those k characters).
        Otherwise, push a new pair (char, 1).
    Build the result from the stack at the end.
    */
    string removeDuplicates(string s) {
        vector<pair<char, int>> stack;

        for(auto& ch : s) {
            if(!stack.empty() && stack.back().first == ch) {
                stack.back().second++;

                if(stack.back().second == 2) {
                    stack.pop_back();
                }
            } else {
                stack.push_back({ch, 1});
            }
        }

        string result = "";
        for(auto& [ch, count] : stack) {
            result.append(count, ch);
        }

        return result;
    }
};