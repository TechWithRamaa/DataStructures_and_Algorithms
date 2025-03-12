class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int N = s.size();
        int M = p.size();

        if (M > N)
            return {};

        vector<int> freqPMap(26, 0); // Frequency map for `p`
        vector<int> freqSMap(26, 0); // Frequency map for the first window in `s`

        for (int i = 0; i < M; i++) {
            freqPMap[p[i] - 'a']++;
            freqSMap[s[i] - 'a']++;
        }

        vector<int> result;
        if (freqPMap == freqSMap)
            result.push_back(0);

        for (int i = M; i < N; i++) {
            freqSMap[s[i] - 'a']++;     // Add new character (right side)
            freqSMap[s[i - M] - 'a']--; // Remove outgoing character (left side)

            if (freqPMap == freqSMap)
                result.push_back(i - M + 1);
        }

        return result;
    }
};