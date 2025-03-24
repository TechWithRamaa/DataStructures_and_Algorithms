class Solution {
public:
    // Approach 1 - TLE
    // BruteForce - Fixed Sliding Window
    // TC ~ O (n * k log k) where k is the window size
    vector<double> medianSlidingWindow1(vector<int>& nums, int k) {

        vector<double> medians;

        for (int i = 0; i + k <= nums.size(); i++) {
            // make a copy of a window
            vector<int> window(nums.begin() + i, nums.begin() + i + k);

            sort(window.begin(), window.end());

            if (k & 1)
                medians.push_back(window[k / 2]);
            else
                medians.push_back(
                    ((double)window[k / 2 - 1] + (double)window[k / 2]) / 2.0);
        }

        return medians;
    }

    // Approach 2
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> medians;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;
        unordered_map<int, int> invalidElementsMap;

        for (int i = 0; i < k; i++)
            maxHeap.push(nums[i]);

        // Balance the heaps so that maxHeap has at most one extra element
        for (int i = 0; i < k / 2; i++) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Step 2: Process the sliding window
        for (int i = k;; i++) {
            
            // Store the median
            if (k % 2 == 1) {
                medians.push_back(maxHeap.top());
            } else {
                medians.push_back(((double)maxHeap.top() + (double)minHeap.top()) / 2.0);
            }

            // Break condition: all elements processed
            if (i >= nums.size())
                break;

            // Incoming and outgoing elements
            int outNum = nums[i - k];
            int inNum = nums[i];

            // Balance factor to keep track of heap adjustments
            int balance = 0;

            // Mark outgoing number for removal
            invalidElementsMap[outNum]++;

            // Determine which heap the outgoing element belongs to
            if (outNum <= maxHeap.top()) {
                balance--; // maxHeap loses an element
            } else {
                balance++; // minHeap loses an element
            }

            // Insert new number into the correct heap
            if (!maxHeap.empty() && inNum <= maxHeap.top()) {
                maxHeap.push(inNum);
                balance++; // maxHeap gains an element
            } else {
                minHeap.push(inNum);
                balance--; // minHeap gains an element
            }

            // Rebalance heaps
            if (balance < 0) { // maxHeap has fewer elements
                maxHeap.push(minHeap.top());
                minHeap.pop();
                balance++;
            }

            if (balance > 0) { // minHeap has fewer elements
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                balance--;
            }

            // Remove invalid elements from the top of the heaps
            while (!maxHeap.empty() && invalidElementsMap[maxHeap.top()]) {
                invalidElementsMap[maxHeap.top()]--;
                maxHeap.pop();
            }

            while (!minHeap.empty() && invalidElementsMap[minHeap.top()]) {
                invalidElementsMap[minHeap.top()]--;
                minHeap.pop();
            }
        }
        return medians;
    }
};