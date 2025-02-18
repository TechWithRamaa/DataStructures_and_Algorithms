/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> iKnow(n, 0), knowMe(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) 
                    continue;
                
                if(knows(i, j)) {
                    iKnow[i] += 1;
                    knowMe[j] += 1;
                } 
            }
        }

        for(int i = 0; i < n; i++) {
            if(iKnow[i] == 0 && knowMe[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};