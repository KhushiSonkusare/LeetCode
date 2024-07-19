#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int maxLength = 0;
        unordered_map<char, int> list;
        int start = 0;  
        for (int end = 0; end < s.size(); end++) {
            char ch = s[end];
            list[ch]++;
            
            while (list[ch] > 1) {
                list[s[start]]--;
                start++;
            }

            count = end - start + 1;
            if (count > maxLength) {
                maxLength = count;
            }
        }
        
        return maxLength;
    }
};
