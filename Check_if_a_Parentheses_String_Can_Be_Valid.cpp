class Solution {
public:
    bool canBeValid(string s, string locked) {
    stack<char> lock;
    if (s.size() % 2 == 1) {
        return false;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            if (lock.size() == 0) {
                if (locked[i] == '1') {
                    return false;
                } else {
                    lock.push('(');
                }
            } else {
                lock.pop();
            }
        } else {
            if (lock.size() != 0) {
                if (locked[i] == '0') {
                    lock.pop();
                } else {
                    lock.push('(');
                }
            } else {
                lock.push('(');
            }
        }
    }

    return lock.size() == 0;
}

    
};