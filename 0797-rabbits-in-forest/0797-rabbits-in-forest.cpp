class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int>
            answerFrequency; // answer -> number of rabbits giving this answer

        for (int answer : answers)
            answerFrequency[answer]++;

        int totalRabbits = 0;

        for (auto& [reportedSameColorCount, rabbitCount] : answerFrequency) {
            int groupSize = reportedSameColorCount +  1; // Each rabbit implies a group of this size
            int numberOfGroups = ceil((double)rabbitCount /groupSize); // How many such groups are needed
            totalRabbits += numberOfGroups * groupSize; // Each group contributes groupSize rabbits
        }

        return totalRabbits;
    }
};