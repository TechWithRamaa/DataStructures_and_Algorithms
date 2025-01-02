//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> valuePerWeight; // Pair of value-to-weight ratio and index

        // Calculate value-to-weight ratio and store with index
        for (int i = 0; i < n; i++) {
            valuePerWeight.push_back({(double)val[i] / wt[i], i});
        }

        // Sort items by value-to-weight ratio in descending order
        sort(valuePerWeight.rbegin(), valuePerWeight.rend());

        double maxValue = 0.0; // Maximum value in the knapsack
        for (const auto& item : valuePerWeight) {
            int index = item.second;
            if (capacity >= wt[index]) {
                // Take the whole item
                maxValue += val[index];
                capacity -= wt[index];
            } else {
                // Take the fraction of the item
                maxValue += item.first * capacity;
                break;
            }
        }

        return maxValue;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
