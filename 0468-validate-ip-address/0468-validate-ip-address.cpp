class Solution {
public:
    string validIPAddress(string IP) {
        if (isIPv4(IP)) return "IPv4";
        if (isIPv6(IP)) return "IPv6";
        return "Neither";
    }

private:
    bool isIPv4(string IP) {
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4) return false;

        for (string part : parts) {
            if (part.empty() || (part.size() > 1 && part[0] == '0')) return false;

            if (!all_of(part.begin(), part.end(), ::isdigit)) return false;

            try {
                int val = stoi(part);
                if (val < 0 || val > 255) return false;
            } catch (...) {
                return false;
            }
        }

        return true;
    }

    bool isIPv6(string IP) {
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8) return false;

        for (string part : parts) {
            if (part.empty() || part.size() > 4) return false;

            // for (char ch : part) {
            //     if (!isxdigit(ch)) return false;
            // }
            
            if (!all_of(part.begin(), part.end(), ::isxdigit)) return false;
        }

        return true;
    }

    vector<string> split(const string& s, char delim) {
        vector<string> tokens;
        string token;
        istringstream iss(s);

        while (getline(iss, token, delim)) {
            tokens.push_back(token);
        }

        // Handle trailing delimiter case (e.g., "1.1.1.")
        if (!s.empty() && s.back() == delim) tokens.push_back("");

        return tokens;
    }
};
