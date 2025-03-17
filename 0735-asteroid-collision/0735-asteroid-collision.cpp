class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int asteroid : asteroids) {
            if(asteroid > 0) {
                st.push(asteroid);
            } else {
                bool destroyed = false;

                while(!st.empty() && st.top() > 0) {
                    if(abs(asteroid) == st.top()) {
                        st.pop();
                        destroyed = true;
                        break;
                    } else if (abs(asteroid) > st.top()) {
                        st.pop();
                    } else {
                        destroyed = true;
                        break;
                    }
                }

                if(!destroyed)
                    st.push(asteroid); 
            }
        }

        vector<int> result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};