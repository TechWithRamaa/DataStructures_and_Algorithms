class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return generateStrobos(n, n);
    }
private:
    vector<string> generateStrobos(int n, int totalLength) {
        if(n == 0)
            return {""};

        if(n == 1)
            return {"0", "1", "8"};
        
        vector<string> middles = generateStrobos(n - 2, totalLength);

        vector<pair<char, char>> strobos = {{'0', '0'}, {'1', '1'}, 
                                            {'8', '8'}, {'6', '9'}, {'9', '6'}};
        vector<string> result;

        for(auto& s : middles) {
            for(auto& p : strobos) {
                if(n == totalLength && p.first == '0')
                    continue;
                result.push_back(p.first + s + p.second);
            }
        }

        return result;
    }
};