class Solution {
/*
Monotonic stacks solve problems involving local peaks, dips, or next greater/smaller patterns.
This problem is global — find two points anywhere with max area — so two pointers are optimal.
*/
public:
    int maxArea(const vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};