class Solution {
public:
    // Binary Search on Answer Space
    // Capacity is the search space 
    // finding left & right is the task 
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = 0, maxCapacity = 0;

        for(auto weight : weights) {
            totalWeight += weight;
            maxCapacity = max(maxCapacity, weight);
        }

        int left = maxCapacity, right = totalWeight;

        while(left < right) {
            int mid = left + ((right - left) / 2);
            
            if(isFeasible(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }

        }
        
        return left;
    }

private:
    bool isFeasible(vector<int>& weights, const int DAYS, const int CAPACITY) {
        int currentCapacity = 0, predictedDays = 1;

        for(auto weight : weights) {
            currentCapacity += weight;

            if(currentCapacity > CAPACITY) {
                predictedDays++;
                currentCapacity = weight; 
            }
        }

        return predictedDays <= DAYS;
    }
};