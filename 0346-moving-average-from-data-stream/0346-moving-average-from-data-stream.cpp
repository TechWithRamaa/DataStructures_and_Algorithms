class MovingAverage {
private:
    int maxSize;
    queue<int> window;
    double currentSum;
public:
    MovingAverage(int size) {
        maxSize = size;
        currentSum = 0.0;
    }
    
     double next(int val) {
        if (window.size() == maxSize) {
            currentSum -= window.front();  // remove oldest
            window.pop();
        }
        
        window.push(val);
        currentSum += val;

        return currentSum / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */