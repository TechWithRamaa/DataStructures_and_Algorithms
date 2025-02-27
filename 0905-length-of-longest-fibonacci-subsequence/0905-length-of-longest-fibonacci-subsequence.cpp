class Solution {
public:
    // Approach 2 -> Hashset
    // TC ~ O ( N ^ 2 * log S )
    // Improvisation from the brute force
    // Internal loop is optimized
    int lenLongestFibSubseq(vector<int>& arr) {
        const int N = arr.size();
        unordered_set<int> s(arr.begin(), arr.end()); // Fast lookup set
        
        int maxLength = 0;
        
        // Try every pair as the start of a Fibonacci-like sequence
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int a = arr[i], b = arr[j];
                int length = 2; // The sequence starts with two numbers
                
                // Extend the sequence as long as a+b exists in the array
                while (s.find(a + b) != s.end()) {
                    int c = a + b;
                    a = b;
                    b = c;
                    length++;
                }
                
                maxLength = max(maxLength, length);
            }
        }
        
        return maxLength >= 3 ? maxLength : 0;
    }

    // Appproach 1 -> BruteForce
    // TC ~ O ( n ^ 3)
    int lenLongestFibSubseq3(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;

        // Try every pair (arr[i], arr[j]) as the first two elements
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j], length = 2;
                for (int k = j + 1; k < n; k++) {
                    if (arr[k] == a + b) { // Fibonacci condition
                        length++;
                        a = b;
                        b = arr[k];
                    }
                }
                maxLen = max(maxLen, length);
            }
        }

        return maxLen >= 3 ? maxLen : 0;
    }
};