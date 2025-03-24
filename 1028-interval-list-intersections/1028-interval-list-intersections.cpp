class Solution {
    // Another interesting problem here
    // Whenever intervals are found in the question,
    // My mind thinks of sorting, merging or overlapping, sweep line ( creating
    // 2 events for 1 interval)

    // but figured out what is the optimal solution for such problem

    // Approach 1 ~ Brute Force ; TC ~ O ( n ^ 2 )
    // Approach 2 ~ 2 Pointer ; TC ~ O ( m + n )
    // Approach 3 ~ Merge Intervals Variation ; TC ~ O ( m + n )
    // Approach 4 ~ Sweep Line ; TC ~ ( (m + n) * log (m + n) )
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        for (auto& f : firstList) {
            for (auto& s : secondList) {
                int start1 = f[0], end1 = f[1];
                int start2 = s[0], end2 = s[1];

                int start = max(start1, start2);
                int end = min(end1, end2);

                // intersection exists
                if (start <= end) {
                    result.push_back({start, end});
                }
            }
        }

        return result;
    }
};