class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int longest = 0, count = 0;

        set = unordered_set<int>(nums.begin(), nums.end());

        for(auto it: set){
            if(set.find(it - 1) == set.end()){
                int x = it;
                count = 1;

                while(set.find(x+1)!= set.end()){
                    count++;
                    x++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};