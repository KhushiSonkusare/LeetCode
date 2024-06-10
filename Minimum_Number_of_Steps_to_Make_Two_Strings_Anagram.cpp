#include <unordered_map>
#include <string>
#include <cmath> // For std::abs
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> S;
        unordered_map<char, int> T;
        for (char ch : s) {
            S[ch]++;
        }
        
        for (char ch : t) {
            T[ch]++;
        }
        
        int count = 0;
        
        
        for (const auto& pair : S) {
            char ch = pair.first;
            if (T.find(ch) != T.end()) {
                count += abs(S[ch] - T[ch]);
                T.erase(ch); 
            } else {
                count += S[ch];
            }
        }
      
        for (const auto& pair : T) {
            count += pair.second;
        }
        
        return count / 2; 
    }
};
