class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> finalEmails;

        for(auto& email : emails) {
            size_t atPosition = email.find('@');
            string localName = email.substr(0, atPosition);
            string domainName = email.substr(atPosition + 1);

            string derivedName = "";

            for(size_t i = 0; i < localName.length(); i++) {
                if(localName[i] == '.') 
                    continue;
                else if(localName[i] == '+')
                    break;
                else
                    derivedName += localName[i];
            }

            string finalDerivedEmail = derivedName + '@' + domainName;
            finalEmails.insert(finalDerivedEmail);
        }

        return finalEmails.size();
    }
};

