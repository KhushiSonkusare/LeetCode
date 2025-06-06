class Solution {
public:

    void lexiNum(int n, int curr, vector<int> &list){
        if(curr>n)
            return;
        list.push_back(curr);

        for(int i = 0; i<10; i++){
            lexiNum(n, curr*10 + i, list);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> list;

        for(int i = 1; i<=9; i++){
            lexiNum(n, i, list);
        }

        return list;
    }
};