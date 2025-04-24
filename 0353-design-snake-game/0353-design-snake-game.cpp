class SnakeGame {
private:
    int width, height, score, foodIndex;

    vector<vector<int>> food;
    deque<pair<int, int>> snake;
    unordered_set<string> bodySet;
    
    unordered_map<string, pair<int, int>> directions = {
        {"U", {-1, 0}}, {"D", {1, 0}}, 
        {"L", {0, -1}}, {"R", {0, 1}}};

    string posKey(int x, int y) { 
        return to_string(x) + "," + to_string(y); 
    }

public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = food;
        
        score = 0;
        foodIndex = 0;

        // Initialize snake at (0, 0)
        snake.push_back({0, 0});
        bodySet.insert(posKey(0, 0));
    }

    int move(string direction) {
        auto dir = directions[direction];

        auto [x, y] = snake.front();
        
        int headX = x + dir.first;
        int headY = y + dir.second;
        
        string headKey = posKey(headX, headY);

        // Check for wall collision
        if (headX < 0 || headX >= height || headY < 0 || headY >= width) {
            return -1;
        }

        // Remove tail first (since head might move into it)
        auto tail = snake.back();
        string tailKey = posKey(tail.first, tail.second);
        
        bodySet.erase(tailKey);
        snake.pop_back();

        // Check for self collision
        if (bodySet.count(headKey)) {
            return -1;
        }

        // Add new head
        snake.push_front({headX, headY});
        bodySet.insert(headKey);

        // Check for food
        if (foodIndex < food.size() 
        && (headX == food[foodIndex][0] && headY == food[foodIndex][1])) {
            score++;

            // Add tail back to simulate growth
            snake.push_back(tail);
            bodySet.insert(tailKey);

            foodIndex++;
        }

        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */