class Solution {
private:
    // Words for numbers less than 20
    const vector<string> belowTwenty = {
        "",        "One",     "Two",       "Three",    "Four",
        "Five",    "Six",     "Seven",     "Eight",    "Nine",
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    // Words for tens
    const vector<string> tens = {"",       "",      "Twenty", "Thirty",
                                 "Forty",  "Fifty", "Sixty",  "Seventy",
                                 "Eighty", "Ninety"};

    // Scales for powers of 1000
    const vector<string> scales = {"", "Thousand", "Million", "Billion"};

    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20)
            return belowTwenty[num];
        else if (num < 100)
            return tens[num / 10] + (num % 10 ? " " + belowTwenty[num % 10] : "");
        else
            return belowTwenty[num / 100] + " Hundred" + (num % 100 ? " " + helper(num % 100) : "");
    }

public:
    string numberToWords(int num) {
        int i = 0;
        string result = "";

        if (num == 0)
            return "Zero";

         while (num > 0) {
            int chunk = num % 1000;
            if (chunk != 0) {
                string part = helper(chunk);
                
                if (!scales[i].empty())
                    part += " " + scales[i];

                result = part + (result.empty() ? "" : " " + result);
            }
            num /= 1000;
            i++;
        }

        return result;
    }
};