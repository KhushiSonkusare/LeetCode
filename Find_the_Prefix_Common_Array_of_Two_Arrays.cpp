#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> fre(A.size(), 0);
        vector<int> ans(A.size(), 0); 
        int temp = 0; 

        for (int i = 0; i < A.size(); i++) {
            fre[A[i] - 1]++;
            if (fre[A[i] - 1] == 2) temp++;

            fre[B[i] - 1]++;
            if (fre[B[i] - 1] == 2) temp++;

            ans[i] = temp;
        }

        return ans;
    }
};
