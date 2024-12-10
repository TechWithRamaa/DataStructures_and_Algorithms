class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        initialize(k, nums, heap);
    }
    
    int add(int val) {
        return updateHeap(val, k, heap);
    }
private:
    int k; // The kth largest element
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap; // Min-heap

    // Function to initialize the heap
    void initialize(int kValue, std::vector<int>& nums, std::priority_queue<int, std::vector<int>, std::greater<int>>& heap) {
        k = kValue;
        for (int num : nums) {
            heap.push(num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
    }

    // Function to handle add operation
    int updateHeap(int val, int k, std::priority_queue<int, std::vector<int>, std::greater<int>>& heap) {
        heap.push(val);
        if (heap.size() > k) {
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */