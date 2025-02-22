class Vector2D {
private:
    int row, col;
    vector<vector<int>>& vec;
public:
    Vector2D(vector<vector<int>>& vec) : vec(vec), row(0), col(0) {
        
    }
    
    int next() {
        while(row < vec.size() && col == vec[row].size()) {
            row++;
            col = 0;
        }

        return vec[row][col++];
    }
    
    bool hasNext() {
        while(row < vec.size() && col == vec[row].size()) {
            row++;
            col = 0;
        }

        return row < vec.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */