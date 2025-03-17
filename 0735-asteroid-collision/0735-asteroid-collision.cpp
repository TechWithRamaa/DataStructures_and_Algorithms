class Solution {
public:
    // very very cool problem
    // lots of moving mechanics are there beyond the problem
    // a very good problem to ask for lots of clarifying questions

    // collision will occur only for asteroids moving in opposite direction
    // if a asteroid moves <- and another another moves in -> Collision never happens
    // if a asteroid moves -> and another another moves in <- Collision happens

    // we have to return the remaining asteroids in space (sometimes empty)

    // if a negative asteroid arrives, it has to collide with the most recent positive asteroid
    // we should be able to retrieve the right most positive asteroid in O ( 1 ) for efficiency
    // stack becomes a perfect candidate for this problem

    // TC ~ O ( n  + n + n ) ; SC ~ O ( n ) 
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int asteroid : asteroids) {
            // case 1 -> INCOMING positive asteroid drifts away, never collides
            // add directly into stack
            if(asteroid > 0) { 
                st.push(asteroid);
            } else {
                // case 2 -> INCOMING negative asteroid 

                // destroyed is about incoming asteroid
                bool destroyed = false;

                // INCOMING negative asteroid collides with existing positive asteroid ITERATIVELY
                // else add it to stack directly
                while(!st.empty() && st.top() > 0) {
                    // case 1 
                    if(abs(asteroid) == st.top()) {
                        st.pop();
                        destroyed = true;
                        break;
                    } else if (abs(asteroid) > st.top()) { // case 2
                        st.pop();
                    } else {    // case 3
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