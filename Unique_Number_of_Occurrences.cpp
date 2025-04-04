class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int i: arr){
            freq[i]++;
        }

        set<int> f;
        for(const auto& pair: freq){
            f.insert(pair.second);
        }

        if(f.size() == freq.size())
            return true;
        
        return false;
    }
};