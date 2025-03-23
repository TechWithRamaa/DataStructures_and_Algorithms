/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum(nestedList, 1);
    }

private:
    // Approach 1 ~ Recursion
    // TC ~ O ( n )
    int depthSum1(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;

        for (auto& ni : nestedList) {
            if (ni.isInteger()) {
                sum += ni.getInteger() * depth;
            } else {
                sum += depthSum(ni.getList(), depth + 1);
            }
        }

        return sum;
    }

    // Approach 2 ~ Stack data structure
    // TC ~ O ( n )
    int depthSum2(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;

        stack<pair<vector<NestedInteger>, int>> s;
        s.push({nestedList, depth});

        while (!s.empty()) {
            auto [nestedList, d] = s.top();
            s.pop();

            for (auto& ni : nestedList) {
                if (ni.isInteger()) {
                    sum += ni.getInteger() * d;
                } else {
                    s.push({ni.getList(), d + 1});
                }
            }
        }

        return sum;
    }

    // Approach 3 ~ Queue data structure
    // TC ~ O ( n )
    int depthSum(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;

        queue<pair<NestedInteger, int>> q;
        for (auto& ni : nestedList) {
            q.push({ni, 1});
        }

        while (!q.empty()) {
            auto [ni, d] = q.front();
            q.pop();

            if (ni.isInteger()) {
                sum += ni.getInteger() * d;
            } else {
                for (auto& innerNi : ni.getList()) {
                    q.push({innerNi, d + 1});
                }
            }
        }

        return sum;
    }
};