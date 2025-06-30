class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num : nums){
            map[num]++;
        }

        int maxi = 0;

        for(auto& it : map){
            int key = it.first;
            if(map.find(key + 1) != map.end()){
                maxi = max(maxi, map[key] + map[key + 1]);
            }
        }

        return maxi;
    }
};
