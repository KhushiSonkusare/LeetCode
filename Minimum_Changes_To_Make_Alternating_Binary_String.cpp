class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        if(s[0] == '1'){
            count++;
        }
            for(int i = 1; i<size(s);i++){
                if(i % 2 == 0 && s[i]!= '0'){
                    count++;
                }
                if(i % 2 == 1 && s[i]!= '1'){
                    count++;
                }   
            }
        
        int count1 = 0;
        if(s[0] == '0'){
            count1++;
        }
            for(int i = 1; i<size(s);i++){
                if(i % 2 == 0 && s[i]!= '1'){
                    count1++;
                }
                if(i % 2 == 1 && s[i]!= '0'){
                    count1++;
                }   
            }


        return min(count, count1);
    }
};