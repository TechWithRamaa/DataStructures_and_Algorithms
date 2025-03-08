class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int toColor) {
        int ROWS = image.size();
        int COLS = image[0].size();

        if(image[sr][sc] == toColor) 
            return image;

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        int fromColor = image[sr][sc];
        dfs(image, visited, sr, sc, toColor, fromColor);

        return image;   
    }

private:
    void dfs(vector<vector<int>> &image,  vector<vector<bool>>& visited, 
                    int sr, int sc, int toColor, int fromColor) {
        
        visited[sr][sc] = true;
        if(image[sr][sc] == fromColor) {
            image[sr][sc] = toColor;
        }

        int ROWS = image.size();
        int COLS = image[0].size();

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(auto [nr, nc] : directions) {
            int nextR = nr + sr;
            int nextC = nc + sc;

            if(nextR >= 0 && nextR < ROWS && nextC >= 0 && nextC < COLS 
                && image[nextR][nextC] == fromColor 
                && !visited[nextR][nextC]) {
                dfs(image, visited, nextR, nextC, toColor, fromColor);
            }
        }

    }

};