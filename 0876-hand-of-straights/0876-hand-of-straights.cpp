class Solution {
public:
    /*
    Greedy with frequency map: Sort the cards, and for each smallest available card, 
    try to form a consecutive sequence of length groupSize by consuming frequencies; if not possible, return false.
    */
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int N = hand.size();
        
        if(N % groupSize != 0)
            return false;
        
        sort(hand.begin(), hand.end());

        unordered_map<int, int> freqMap; 
        for(int card : hand)
            freqMap[card]++;

        for(int currentCard : hand) {
            if(freqMap[currentCard] == 0) 
                continue;
            
            for(int i = 0; i < groupSize; i++) {
                int nextCard = currentCard + i;

                if(freqMap[nextCard] == 0)
                    return false;
                
                freqMap[nextCard]--;
            }
        }

        return true;
    }
};