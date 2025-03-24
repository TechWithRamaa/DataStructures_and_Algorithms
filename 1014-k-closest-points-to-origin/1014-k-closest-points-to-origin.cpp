class Solution {
    // Multiple approaches to solve this problem exists
    // Very interesting application of Data Structures & Algorithms
    
    // Approach 1 ~ MultiSet
    // Approach 2 ~ maxHeap
    // Approach 3 ~ QuickSelect 
public:
    // TC ~ O (n log k)
    // SC ~ O (k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for(auto point : points) {
            int distance = getEuclideanDistance(point);
            maxHeap.push({distance, point});

            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;
        while(!maxHeap.empty()) {
            auto [distance, point] = maxHeap.top();
            maxHeap.pop();

            result.push_back(point);
        }

        return result;
    }
private:
    int getEuclideanDistance(vector<int>& x) {
        return x[0] * x[0] + x[1] * x[1];
    }
};