class Solution {
public:
    /*
    Key Idea (Greedy Approach)
    Filter triplets:
    
    A triplet [x, y, z] can contribute to the final target [tx, ty, tz] only if:
        x <= tx, y <= ty, and z <= tz.
        Otherwise, it can't help because we can't reduce values.

    Track progress:
    We need to check if, by combining valid triplets, we can cover all three target values:
        Did we find a triplet with x == tx?
        Did we find a triplet with y == ty?
        Did we find a triplet with z == tz?

    If all three conditions are satisfied, return true. Otherwise, false.
    */
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false;

        for(auto& t : triplets) {
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                if(t[0] == target[0]) 
                    a = true;
                if(t[1] == target[1]) 
                    b = true;
                if(t[2] == target[2]) 
                    c = true;
            }
        } // complete all given triplet in the triplets 2D. To ensure  x <= tx, y <= ty, and z <= tz always

        return a && b && c;
    }
};