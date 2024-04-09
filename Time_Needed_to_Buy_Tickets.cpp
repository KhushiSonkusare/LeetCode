#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        
        // Continue until tickets for type k are exhausted
        while (tickets[k] != 0) {
            int minCount = INT_MAX; // Initialize minCount to maximum possible value
            int totalCount = 0; // Initialize totalCount of non-zero tickets
            // Find the minimum count of tickets among all types and count non-zero tickets
            for (int i = 0; i < tickets.size(); ++i) {
                if (tickets[i] > 0) {
                    ++totalCount; // Increment total count of non-zero tickets
                    if (tickets[i] < minCount) {
                        minCount = tickets[i];
                    }
                }
            }
            time += minCount * totalCount; // Update time
            // Reduce the count of tickets for all types by minCount
            for (int i = 0; i < tickets.size(); ++i) {
                tickets[i] -= minCount;
            }
        }
        
        return time;
    }
};
