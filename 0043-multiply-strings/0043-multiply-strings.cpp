class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int M = num1.size(), N = num2.size();
        vector<int> result(M + N, 0);

        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int d1 = num1[i] - '0';
                int d2 = num2[j] - '0';
                int mul = d1 * d2;

                int posLow = i + j + 1;
                int posHigh = i + j;

                int sum = result[posLow] + mul;

                result[posLow] = sum % 10;
                result[posHigh] += sum / 10;
            }
        }

        string product;

        for (int digit : result) {
            if (product.empty() && digit == 0) 
                continue;
            product.push_back(digit + '0');
        }

        return product.empty() ? "0" : product;
    }
};
