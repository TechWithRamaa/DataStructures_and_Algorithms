class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
       string encodedString;

        for(const auto& s: strs) {
            for(const char c : s) {
                if(c == '/') {
                    encodedString += "//";
                } else {
                    encodedString += c;
                }
            }
            encodedString += "/:";
        } 

        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decodedStrings;

        string currentString;

        for(size_t i = 0; i < s.size() - 1; i++) {
            if(s[i] == '/' && s[i+1] == ':') {
                decodedStrings.push_back(currentString);
                currentString.clear();

                i++; // skip 1 extra character in case of delimiter
            } else if (s[i] == '/' && s[i+1] == '/') {
                currentString += '/';
                
                i++; // skip 1 extra character in case of /
            } else {
                currentString += s[i];
            }
        }

        return decodedStrings;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));