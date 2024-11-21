class Solution {
public:
    int sumSubarrayMins(const vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        // Arrays to store indices of Previous Small Element and Next Small Element
        vector<int> PSE(n, -1);
        vector<int> NSE(n, n);

        stack<int> s;

        // Find Previous Small Element Index
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) 
                s.pop();
            
            PSE[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear the stack to reuse
        while (!s.empty())
            s.pop();

        // Find Next Small Element
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            
            NSE[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate the result
        // Leveraging mathematical insights for optimizing Computational costs
        // incurred with Brute force approach
        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - PSE[i];
            long long right = NSE[i] - i;
            
            result = (result + arr[i] * left * right) % MOD;
        }

        return result;
    }
};