class Solution {
public:
    bool isStrobogrammatic(string num) {

        unordered_map<char, char> strobos = {{'0', '0'}, 
        {'1' , '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

        int N = num.size();

        if(N == 1) 
            return strobos[num[0]] == num[0];

        int left = 0, right = N - 1;
        while(left <= right) {
            char leftC = num[left];
            char rightC = num[right];

            if(strobos.find(leftC) == strobos.end() || strobos[leftC] != rightC)
                return false;

            left++;
            right--;
        }

        return true;
    }
};