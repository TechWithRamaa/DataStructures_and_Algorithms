class Solution {
public:
    // Approach 1 -> 3 Lists Approach
    // BruteForce ~ O ( N ) ; TC ~ O (N)
    vector<int> pivotArray1(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;

        for (int num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num == pivot) {
                equal.push_back(num);
            } else {
                greater.push_back(num);
            }
        }

        vector<int> result;
        result.reserve(nums.size());
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }

    // Approach 2 -> Counter In-Place approach
    // TC ~ O ( N ) ; SC ~ O ( 1 )
    vector<int> pivotArray2(vector<int>& nums, int pivot) {
        vector<int> result(nums.size());

        int index = 0;
        for (auto num : nums) {
            if (num < pivot) {
                result[index++] = num;
            }
        }

        for (auto num : nums) {
            if (num == pivot) {
                result[index++] = num;
            }
        }

        for (auto num : nums) {
            if (num > pivot) {
                result[index++] = num;
            }
        }

        return result;
    }

    // Approach 3 -> Counting + Partition based
    // TC ~ O ( N ) ; SC ~ O ( 1 )
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int countLeft = 0, countMid = 0;

        // Step 1: Count occurrences
        for (int num : nums) {
            if (num < pivot)
                countLeft++;
            else if (num == pivot)
                countMid++;
        }

        // Compute starting indices
        int leftIndex = 0;
        int midIndex = countLeft;
        int rightIndex = countLeft + countMid;

        vector<int> result(nums.size());

        // Step 2: Fill the result array in one pass
        for (int num : nums) {
            if (num < pivot)
                result[leftIndex++] = num;
            else if (num == pivot)
                result[midIndex++] = num;
            else
                result[rightIndex++] = num;
        }

        return result;
    }
};