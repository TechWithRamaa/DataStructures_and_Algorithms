class StockSpanner {
private:
    // monotonic decreasing stack
    // for previous greater elements
    // pair of stock price, index is maintained
    stack<pair<int, int>> st;
    int index;
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        int span = 1;

        // step 1 -> pop the smaller elements
        while(!st.empty() && st.top().first <= price)  
            st.pop();

        // step 2 -> calculate the span
        index++;

        if(!st.empty())
            span = index - st.top().second;
        else 
            span = index;

        // step 3 -> push the current price into stack
        st.push({price, index});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */