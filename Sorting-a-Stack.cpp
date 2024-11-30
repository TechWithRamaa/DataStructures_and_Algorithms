/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack :: sort() {
    stack<int> auxStack;

    // Sort the stack using the auxiliary stack
    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        // Move elements from auxStack back to s if they are greater than temp
        while (!auxStack.empty() && auxStack.top() < temp) {
            s.push(auxStack.top());
            auxStack.pop();
        }

        // Insert temp into auxStack
        auxStack.push(temp);
    }
    // Transfer elements back to the original stack
    while (!auxStack.empty()) {
        s.push(auxStack.top());
        auxStack.pop();
    }
}


void SortedStack::sortedInsert(int element) {
    // If the stack is empty or the element is greater than the top, push it
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }

    // Otherwise, pop the top element
    int topElement = s.top();
    s.pop();

    // Recursively insert the element in the sorted stack
    sortedInsert(element);

    // Put the popped element back on top
    s.push(topElement);
}

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack::sort() {
    // Base case: If the stack is empty, return
    if (s.empty()) return;

    // Remove the top element
    int topElement = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sort();

    // Insert the removed element back into the sorted stack
    sortedInsert(topElement);
}
