class HitCounter {
private:
    queue<int> hits;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hits.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(!hits.empty() && timestamp - hits.front() >= 300) {
            hits.pop();
        }

        return hits.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */