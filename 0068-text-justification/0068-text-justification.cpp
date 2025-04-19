class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        int noOfWords = words.size();
        int starting = 0, ending = 0;

        while (starting < noOfWords) {
            int lineLength = 0;
            ending = starting;

            // Try to fit as many words as possible into the line
            while (ending < noOfWords &&
                   (lineLength + words[ending].length() + (ending - starting)) <= maxWidth) {

                lineLength += words[ending].length();
                ending++;
            }

            int totalWords = ending - starting;
            int freeSpaceSlot = maxWidth - lineLength;

            string line;

            // Case 1: Last line or single word
            if(ending == noOfWords || totalWords == 1) {
                 for (int k = starting; k < ending; k++) {
                    line += words[k];

                    if (k < ending - 1) 
                        line += " ";
                }
                // Fill the remaining spaces to the right
                line += string(maxWidth - line.length(), ' ');
            } else {
                // Case 2: Fully justify
                int gaps = totalWords - 1;
                int spaceBetweenWords = freeSpaceSlot / gaps;
                int extraSpace = freeSpaceSlot % gaps;

                for(int k = starting; k < ending; k++) {
                    line += words[k];

                    if(k < ending - 1) {
                        int spacesToAdd = spaceBetweenWords + (extraSpace-- > 0 ? 1 : 0);
                        line += string(spacesToAdd, ' ');
                    }                    
                }
            }

            result.push_back(line);
            starting = ending;
        }

        return result;
    }
};