class Solution {
public:
    /*
    Greedy + Monotonic Stack Approach
    
    Iterate through each digit in the number.
    Use a stack to build the result:
        While the stack is not empty, k > 0, and top of stack > current digit, pop from the stack (remove the larger digit).
        Push the current digit onto the stack.
    If k > 0 after processing all digits, remove the last k digits from the stack (because we still need to remove digits).
    Remove any leading zeros.
    If the result is empty, return "0".
    */
    string removeKdigits(string num, int k) {
        string stack; // using a string itself as a stack 

        for(auto& ch: num) {
            while(!stack.empty() && k > 0 && stack.back() > ch) {
                stack.pop_back(); // Remove the last character or the previous largest number
                k--;
            } 

            stack.push_back(ch);
        }

        // If k > 0, remove from the end
        while(k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        size_t i = 0;
        while(i < stack.size() && stack[i] == '0') // skips leading zeros
            i++;

        stack = stack.substr(i);

        return stack.empty() ? "0" : stack;
    }
};