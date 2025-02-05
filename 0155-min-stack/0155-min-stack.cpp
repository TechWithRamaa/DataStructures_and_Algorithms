class MinStack {
private:
    stack<int> auxillaryStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        auxillaryStack.push(val);
        if(minStack.empty() || minStack.top() >= val) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if(!auxillaryStack.empty()) {
           int top = auxillaryStack.top();
           auxillaryStack.pop();
           if(minStack.top() == top) {
            minStack.pop();
           }
        }
    }
    
    int top() {
        if(!auxillaryStack.empty()) {
            return auxillaryStack.top();
        }
        throw std::out_of_range("auxillaryStack is empty");
    }
    
    int getMin() {
        if(!minStack.empty()) {
            return minStack.top();
        }
        throw std::out_of_range("minStack is empty");
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