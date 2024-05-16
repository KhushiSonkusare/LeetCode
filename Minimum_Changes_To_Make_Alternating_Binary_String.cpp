class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        if(s[0] == '0'){
            for(int i = 1; i<size(s);i++){
                if(i % 2 == 0 && s[i]!= '0'){
                    count++;
                }
                if(i % 2 == 1 && s[i]!= '1'){
                    count++;
                }   
            }
            return count;
        }
        int count1 = 0;
        if(s[0] == '1'){
            for(int i = 1; i<size(s);i++){
                if(i % 2 == 0 && s[i]!= '1'){
                    count1++;
                }
                if(i % 2 == 1 && s[i]!= '0'){
                    count1++;
                }   
            }
            return count1;
        }

        return 0;
    }
};