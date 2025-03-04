#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; // Stack to store moving right asteroids

        for (int asteroid : asteroids) {
            bool destroyed = false;

            // Handle collisions
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (abs(asteroid) > st.top()) {
                    st.pop(); // Right-moving asteroid is destroyed
                } else if (abs(asteroid) == st.top()) {
                    st.pop(); // Both asteroids are destroyed
                    destroyed = true;
                    break; // No need to check further
                } else {
                    destroyed = true; // Left-moving asteroid is destroyed
                    break;            // No need to check further
                }
            }

            if (!destroyed) {
                st.push(asteroid); // Push only if it wasn't destroyed
            }
        }

        // Convert stack to vector (in correct order)
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
