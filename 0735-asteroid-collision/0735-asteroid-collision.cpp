#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {
            bool exploded = false;

            while (!st.empty() && st.top() > 0 && ast < 0) { // Collision happens
                if (abs(st.top()) < abs(ast)) { // Right-moving asteroid is smaller
                    st.pop();
                    continue; // Keep checking further collisions
                } else if (abs(st.top()) == abs(ast)) { // Both are equal, both explode
                    st.pop();
                }
                exploded = true;
                break;
            }

            if (!exploded) {
                st.push(ast);
            }
        }

        vector<int> result(st.size());
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
