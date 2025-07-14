class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<>> minHeap;

        for(const auto& value : sticks) {
            minHeap.push(value);
        }

        int minCost = 0, sum = 0;
        while(minHeap.size() > 1) {
            int x = minHeap.top();
            minHeap.pop();

            int y = minHeap.top();
            minHeap.pop();

            sum = (x + y);
            minCost += sum;
            
            minHeap.push(sum);
        }

        // if(!minHeap.empty())
        //     minCost += minHeap.top();

        return minCost;
    }
};


