class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0 , count = 0;

        map<int, int> mapp;
        mapp[0] = 1;

        for(int  i =0; i<nums.size(); i++){
            prefix+= nums[i];

            int remove = prefix - k;

            count+= mapp[remove];
            mapp[prefix]++;
        }

        return count;
    }
};