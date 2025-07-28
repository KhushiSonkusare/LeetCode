class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();
        vector<vector<int>> ans;

        // Step 1: Add intervals that come before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval); // Add the merged interval

        // Step 3: Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
