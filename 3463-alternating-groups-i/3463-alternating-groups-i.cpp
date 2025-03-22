class Solution {
public:
    // Core skill required
    // Array wrapping
    int numberOfAlternatingGroups(vector<int>& colors) {
        int solution = 0;
        int N = colors.size();

        for(int current = 0; current < N; current++) {
            // for dealing with negative indices
            // adding + N before taking Mod N ensures it naturally adjusts the indices
            int previous = ( current - 1 + N ) % N;
            int next = ( current + 1 ) % N;

            if(colors[previous] != colors[current] 
                && colors[current] != colors[next]) {
                solution++;
            }
        }

        return solution;
    }
};