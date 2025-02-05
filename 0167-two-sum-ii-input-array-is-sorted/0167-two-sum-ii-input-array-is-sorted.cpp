class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPointer = 0;
        int rightPointer = numbers.size() - 1;

        while(leftPointer < rightPointer) {
            int currentSum = numbers[leftPointer] + numbers[rightPointer];
            
            if(currentSum == target) {
                return {leftPointer + 1, rightPointer + 1};
            } else if(currentSum > target) {
                rightPointer--;
            } else {
                leftPointer++;
            }
        }

        return {};
    }
};