class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<char> lock;
        if(s.size()%2 == 1)
            return false;
        else{
            for(int i = 0; i<s.size(); i++){
                if(s[i] == ')'){
                    if(lock.size() == 0){
                        if(locked[i] == 1)
                            return false;
                        else{
                            s[i] = '(';
                            lock.push('(');
                        }
                    }
                    else{
                        if(lock.size()!=0)
                            lock.pop();
                        else
                            return false;
                    }
                }
                else{
                    if(lock.size()!=0){
                        if(locked[i] == 0){
                            lock.pop();
                        }else{
                            lock.push('(');
                        }
                    }else{
                        lock.push('(');
                    }
                }
            }

            if(lock.size() == 0){
                return true;
            }else
                return false;
        }
        return false;
    }
};