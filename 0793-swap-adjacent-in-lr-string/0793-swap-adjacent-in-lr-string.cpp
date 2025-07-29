class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip 'X' in both strings
            
            while (i < n && start[i] == 'X')
                i++;

            while (j < n && end[j] == 'X')
                j++;

            // If one reaches end before the other → false
            if ((i == n) != (j == n))
                return false;

            // If both done → success
            if (i == n && j == n)
                return true;

            // Check character match
            if (start[i] != end[j])
                return false;

            // Check movement validity
            if (start[i] == 'L' && i < j)
                return false;
                
            if (start[i] == 'R' && i > j)
                return false;

            i++;
            j++;
        }

        return true;
    }
};