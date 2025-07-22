class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> charMap;

        for (int i = 0; i < s.length(); ++i) {
            char sc = s[i];
            char tc = t[i];

            if(charMap.find(sc)!= charMap.end()){
                if(charMap[sc]!=tc){
                    return false;
                }
            }else{
                for(auto it: charMap){
                    if(it.second == tc){
                        return false;
                    }
                }
                charMap[sc] = tc;
            }

        }
        return true;
    }
};