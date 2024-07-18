class Solution {
public:
    void paths(int i , int j , int m, int n, vector<int> &list){
        if(i == m-1 && j == n-1){
            list.push_back(1);
        }

        if(i<m){
            paths(i+1,j,m,n,list);
        }
        if(j<n)
            paths(i,j+1,m,n,list);
    }

    int uniquePaths(int m, int n) {
        vector<int> list;
        paths(0,0,m,n,list);

        return list.size();
    }
};