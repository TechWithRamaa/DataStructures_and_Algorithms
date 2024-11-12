class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int N = arr.size();
        queue<int> q;
        vector<bool> visited(N, false);

        q.push(start);

        while(!q.empty()) {
            int currentIndex = q.front();
            q.pop();

            if(arr[currentIndex] == 0) return true;

            visited[currentIndex] = true;

            int leftJump = currentIndex - arr[currentIndex];
            int rightJump = currentIndex + arr[currentIndex];

            if(leftJump >= 0 && !visited[leftJump]) q.push(leftJump);
            if(rightJump < N && !visited[rightJump]) q.push(rightJump);
        } 

        return false;
    }
};