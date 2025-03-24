#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        int count = 0;
        int lastEnd = 0;  

        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            if (start > lastEnd + 1) {
                count += (start - lastEnd - 1);
            }

            lastEnd = max(lastEnd, end);
        }

        count += (days - lastEnd);

        return count;
    }
};
