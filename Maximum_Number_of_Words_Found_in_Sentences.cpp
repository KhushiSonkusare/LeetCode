#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        
        for (const string& sentence : sentences) {
            int wordCount = 1;
            for (char c : sentence) {
                if (c == ' ') {
                    wordCount++;
                }
            }
            if (wordCount > maxWords) {
                maxWords = wordCount;
            }
        }
        
        return maxWords;
    }
};
