class Solution {
  public:
    vector<string> findPath(const vector<vector<int>> &mat) {
        vector<string> result;
        string path;
        
        const int N = mat.size();
        
        // If the start or end cell is blocked, return an empty list
        if (mat[0][0] == 0 || mat[N-1][N-1] == 0) 
            return result;

        vector<vector<bool>> visited(N, vector<bool>(N, false));
        
        // Direction arrays for moving Down, Left, Right, Up
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, -1, 1, 0};
        
        string directions = "DLRU";

        // Start the backtracking from (0, 0)
        backtrack(mat, N, 0, 0, visited, path, result, dx, dy, directions);
        
        sort(result.begin(), result.end()); // Return lexicographically sorted paths
        
        return result;
    }
    
  private:
    void backtrack(const vector<vector<int>>& mat, const int N, int x, int y,
                   vector<vector<bool>>& visited, string& path, vector<string>& result, 
                   const vector<int>& dx, const vector<int>& dy, const string& directions) {
                       
        //  If the rat reaches the destination, add the path to the result
        if (x == N - 1 && y == N - 1) {
            result.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = true;

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check if the new cell is within bounds, not visited, and not blocked
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && mat[nx][ny] == 1) {
                path.push_back(directions[i]); // Add the direction to the path
                backtrack(mat, N, nx, ny, visited, path, result, dx, dy, directions);
                path.pop_back(); // Backtrack
            }
        }

        // Unmark the current cell for other paths - Backtrack
        visited[x][y] = false;
    }    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
