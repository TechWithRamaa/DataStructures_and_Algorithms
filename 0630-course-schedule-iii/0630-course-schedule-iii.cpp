class Solution {
public:
    /* Fails for all test cases, dont have functionalities to swap 
       the longer courses with 2 shorter courses
       Goal is to maximize the no of courses taken 
    int scheduleCourse(vector<vector<int>>& courses) {
        // sort based on the last day ie second parameter in ascending order
        sort(courses.begin(), courses.end(), [] (const vector<int>&a, const vector<int>&b) {
            return a[1] < b[1];
        });

        int currentDay = 0, count = 0;
        for(const auto& current : courses) {
            int duration = current[0], lastDay = current[1];
    
            int projectedCompletion = currentDay + duration;
            if(projectedCompletion <= lastDay) {
                count++;
                currentDay += duration;
            }
        }

        return count;
    }
    */

    int scheduleCourse(vector<vector<int>>& courses) {
        // sort based on the last day ie second parameter in ascending order
        sort(courses.begin(), courses.end(), [] (const vector<int>&a, const vector<int>&b) {
            return a[1] < b[1];
        });

        // stores the duration of courses. 
        // Longest Duration will be at the top so that
        // course with the longest duration can be swappable with few upcoming smaller courses
        // which maximizes the no of courses
        priority_queue<int> maxHeap; 
        int currentDay = 0;

        for(const auto& course : courses) {
            int duration = course[0], lastDay = course[1];
            
            currentDay += duration;
            maxHeap.push(duration);

            if(currentDay > lastDay) {
                currentDay -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};

