class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> finalPrices(prices.begin(), prices.end());

        stack<int> st;

        for(int i = prices.size() - 1; i >= 0; i--) {
            // step 1 - pop greater elements
            while(!st.empty() && st.top() > prices[i]) 
                st.pop();

            // step 2 - apply discount
            if(!st.empty()) 
                finalPrices[i] -= st.top();

            // step 3 - push the element
            st.push(prices[i]);
        }

        return finalPrices;
    }
};