class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) 
            return "1";
        
        string previousTerm = countAndSay(n-1);
        
        string currentTerm = "";
        int count = 1;
        
        for(int i = 1; i < previousTerm.length(); i++) {
            if(previousTerm[i] == previousTerm[i-1]) {
                count += 1;
            } else {
                currentTerm += to_string(count) + previousTerm[i - 1];
                count = 1;
            }          
         }
         
        currentTerm += to_string(count) + previousTerm[previousTerm.length() - 1];
            
        return currentTerm;
    }
};



// n = 4    gets "21" .. produces "1211"
    // n = 3    gets "11" .. produces "21"
        // n = 2   gets "1" .. produces "11"
            // n = 1 returns "1"