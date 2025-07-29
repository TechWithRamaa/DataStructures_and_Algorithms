class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result; // Final set of all ORs
        unordered_set<int> prev;   // ORs of subarrays ending at previous index

        for (int num : arr) {
            unordered_set<int> curr; // ORs ending at this position
            curr.insert(num);        // Start a new subarray with just arr[i]

            for (int x : prev) {
                curr.insert( num | x); // Extend previous subarrays by adding current element
            }

            for (int x : curr) {
                result.insert(x); // Add all ORs ending here to global result
            }

            prev = curr; // Update for next round
        }

        return result.size();
    }
};