class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);   // Store result time for each function
        stack<int> st;              // Simulates call stack
        int prevTime = 0;           // Last recorded time

        for (const string& log : logs) {
            auto [id, type, time] = parseLog(log);

            if (type == "start") {
                if (!st.empty())
                    result[st.top()] += time - prevTime;  // Pause current

                st.push(id);             // Start new function, zero th call
                prevTime = time;         // Update prevTime
            } else {
                result[st.top()] += time - prevTime + 1;  // Include end
                st.pop();               // Function ends
                
                prevTime = time + 1;    // Resume next from next unit
            }
        }

        return result;
    }

private:
    tuple<int, string, int> parseLog(const string& log) {
        istringstream ss(log);
        string idStr, type, timeStr;

        getline(ss, idStr, ':');
        getline(ss, type, ':');
        getline(ss, timeStr, ':');

        return {stoi(idStr), type, stoi(timeStr)};
    }
};