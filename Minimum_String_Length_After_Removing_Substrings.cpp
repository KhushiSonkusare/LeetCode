class Solution {
public:
    int minLength(string s) {
        stack<char> stack;
        for(char i: s){
            if((!stack.empty()) && ((stack.top() == 'A' and i == 'B') || (stack.top() == 'C' and i == 'D'))){
                stack.pop();
            }
            else{
                stack.push(i);
            }
        }
        return stack.size();
    }
};