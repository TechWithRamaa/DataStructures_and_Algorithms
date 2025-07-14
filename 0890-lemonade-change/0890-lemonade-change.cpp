class Solution {
public:
    // I initially thought greedy simulation using Stack
    // but just 2 counter variables is enough to solve this
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for(int bill : bills) {
            if(bill == 5) {
                five++;
            } else if (bill == 10) {
                if(five == 0) 
                    return false;
                
                five--;
                ten++;                
            } else {
                if(ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if(five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};