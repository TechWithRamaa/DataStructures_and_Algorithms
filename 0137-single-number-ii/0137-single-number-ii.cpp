class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int singleNumber = 0, shift = 1;

        for(int i = 0; i < 32; i++) {
            int count = 0;

            for(auto element : nums) {
                if(element & shift) 
                    count++;
            }

            // If count is not a multiple of 3, this bit belongs to the single number
            if(count%3 != 0) 
                 singleNumber |= shift;
            
            shift <<= 1; // Shift left by 1 instead of multiplying by 2
        }

        return singleNumber;
    }
};