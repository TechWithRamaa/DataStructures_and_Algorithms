class Solution {
public:
    string addBinary(string a, string b) {
        int M = a.size(), N = b.size();

        int i = M - 1, j = N - 1;
        int carry = 0;

        string result = "";

        while(i >= 0 || j >= 0) {
            int bitOfA = (i >= 0) ? a[i] - '0' : 0;
            int bitOfB = (j >= 0) ? b[j] - '0' : 0;

            int temp = bitOfA + bitOfB + carry;

            if(temp == 2) {
                carry = 1;
            }

            result.push_back((temp % 2) + '0');
            carry = temp / 2;
            i--; j--;
        } 

        if(carry > 0)
            result.push_back(carry + '0');

        reverse(result.begin(), result.end());
        return result;
    }
};