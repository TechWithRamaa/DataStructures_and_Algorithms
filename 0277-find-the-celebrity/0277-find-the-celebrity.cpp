/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    /* 4 or 5 approaches are there 

    approach 1 -> Nested loops -> If i knows j but j don't know i, then i cannot be a celebrity ~ O(n ^ 2) 
    approach 2 -> Stack based -> Push all candidates into stack, iteratively pop every candidate until there is atmost 1 candidate in the stack
    approach 3 -> IKnow & KnowMe vectors ~ O (N ^ 2); SC ~ O (2N) 
    approach 4 -> Two Pointers ~ O (2N); SC ~ O (1)
    */
public:
    int findCelebrity(int n) {
        int top = 0, down = n - 1;
        // top is pointing at 0th candidate
        // down is pointing at n-1 th candidate
        
        while(top < down) {
            if(knows(top, down)) {
                top++;
            } else {
                down--;
            }
        }

        int potentialCelebrity = top;
        // VERIFICATION
        for(int k = 0; k < n ; k++) {
            if(k == potentialCelebrity)
                continue;

            if(knows(potentialCelebrity, k) || !knows(k, potentialCelebrity)) 
                return -1;
        }

        return potentialCelebrity;
    }

    int findCelebrityApproach3(int n) {
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

        // VERIFICATION 
        for(int i = 0; i < n; i++) {
            if(iKnow[i] == 0 && knowMe[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};