class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector <int> ans(nums.size(), -1);
        stack <int> v;

        for(int j=0; j<2; ++j){
            for(int i=0; i<nums.size(); ++i){
                while(!v.empty() && nums[v.top()] < nums[i]){
                    int stackTop = v.top();
                    v.pop();
                    ans[stackTop] = nums[i];
                }
                if (j == 0) v.push(i);
            }
        }
        return ans;
    }
};