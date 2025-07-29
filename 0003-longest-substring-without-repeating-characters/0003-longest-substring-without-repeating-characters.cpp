class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, count = 0, maxi = 0;

        unordered_map<char, int> map;

        for(int right = 0; right < s.size(); right++){
            map[s[right]]++;

            while(map[s[right]] > 1 && left <= right){
                map[s[left]]--;
                left++;
            }

            maxi = max(maxi, right -left +1);
        }

        return maxi;

    }
};