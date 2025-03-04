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
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;

        for(auto num : nums) {
            if(num < pivot) {
                result.push_back(num);
            }
        }   

        for(auto num : nums) {
            if(num == pivot) {
                result.push_back(num);
            }
        } 

         for(auto num : nums) {
            if(num > pivot) {
                result.push_back(num);
            }
        } 

        return result;
    }
};