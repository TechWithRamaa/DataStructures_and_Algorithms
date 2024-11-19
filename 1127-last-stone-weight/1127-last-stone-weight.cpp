class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
          priority_queue<int> maxHeap;

        for(int stone : stones)
            maxHeap.push(stone);
        
        while(maxHeap.size() > 1) {
            int stoneA = maxHeap.top();
            maxHeap.pop();

            int stoneB = maxHeap.top();
            maxHeap.pop();

            if(stoneA != stoneB) 
                maxHeap.push(abs(stoneA - stoneB));
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};