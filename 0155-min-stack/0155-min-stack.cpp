class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || minStack.top() >= val) {
            minStack.push(val);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            if (minStack.top() == mainStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        throw out_of_range("Stack is empty");
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        throw out_of_range("Min stack is empty");
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */