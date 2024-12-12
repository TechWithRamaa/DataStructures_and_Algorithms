class MedianFinder {
private:
    priority_queue<int> maxHeap; // Max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for the upper half
public:
    // Initialize the data structure
    MedianFinder() {}

    // Add a number into the data structure
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Find the median of the data stream
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) 
            return (maxHeap.top() + minHeap.top()) / 2.0;
         else 
            return maxHeap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */