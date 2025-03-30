class Solution {
public:
    // Reframe the problem
    // Smallest Lexicographic subsequence of length k
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int N = nums.size();

        stack<int> st;

        for(int i = 0; i < N; i++) {
            while(!st.empty() && st.top() > nums[i] && (st.size() + (N - i) > k)) 
                st.pop();
            

            if(st.size() < k)
                st.push(nums[i]);
        }

        vector<int> result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};


/*
1️⃣ Start with the Problem Constraints

- We need a subsequence of size k.
- We can remove elements if it helps maintain a lexicographically smaller order.
- We must maintain relative order (i.e., no reordering of elements).

\U0001f449 The core question becomes:
- "When is it safe to remove an element?"

*/