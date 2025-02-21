class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
         // Handle special case of numerator 0
        if (numerator == 0) return "0";
        
        string result;
        
        // Determine the sign of the result
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        
        // Convert to long long to prevent overflow and work with positive values
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        
        // Append the integer part
        long long integerPart = n / d;
        result += to_string(integerPart);
        
        // Calculate the remainder
        long long remainder = n % d;
        if (remainder == 0) {
            return result;
        }
        
        // Process the fractional part
        result += ".";
        unordered_map<long long, int> remainderPositions;
        
        while (remainder != 0) {
            // If we have seen this remainder before, a repeating sequence is found
            if (remainderPositions.find(remainder) != remainderPositions.end()) {
                int pos = remainderPositions[remainder];
                result.insert(pos, "(");
                result += ")";
                break;
            }
            
            // Store the position for the current remainder
            remainderPositions[remainder] = result.size();
            
            // Multiply remainder by 10 to get the next digit
            remainder *= 10;
            long long digit = remainder / d;
            result += to_string(digit);
            remainder %= d;
        }
        
        return result;
    }
};