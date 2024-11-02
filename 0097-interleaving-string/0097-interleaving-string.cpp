class Solution {
public:
    bool isInterleave(const string& s1, const string& s2, const string& s3) {
        const int S1_LENGTH = s1.length();
        const int S2_LENGTH = s2.length();
        const int S3_LENGTH = s3.length();

        if((S1_LENGTH + S2_LENGTH) != S3_LENGTH) 
            return false;

        vector<vector<int>> cache(S1_LENGTH + 1, vector<int>(S2_LENGTH + 1, -1));

        return isInterleave(0, 0, cache, s1, s2, s3);
    }

    bool isInterleave(int s1Index, int s2Index, vector<vector<int>>& cache, const string& s1, const string& s2, const string& s3) {
        if (s1Index == s1.length() && s2Index == s2.length()) return true;

        if(cache[s1Index][s2Index] != -1) return cache[s1Index][s2Index] == 1;

        bool isInterleaveFound = false;

        if(s1Index < s1.length() && s1[s1Index] == s3[s1Index + s2Index])
            isInterleaveFound = isInterleave(s1Index + 1, s2Index, cache, s1, s2, s3);

        if(s2Index < s2.length() && s2[s2Index] == s3[s1Index + s2Index])
            isInterleaveFound |= isInterleave(s1Index, s2Index + 1, cache, s1, s2, s3);

        return cache[s1Index][s2Index] = isInterleaveFound ? 1 : 0;
    }
};