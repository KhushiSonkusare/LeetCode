#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> freq;  // Track the next available day for each task
        long long days = 0;

        for (int i = 0; i < tasks.size(); i++) {
            if (freq.find(tasks[i]) == freq.end() || days >= freq[tasks[i]]) {
                // If the task is not in the map or its cooldown period is over, execute it on the current day
                days++;
            } else {
                // If the task is in the map and its cooldown period is not over, wait until the next available day
                days = freq[tasks[i]];
            }
            // Update the next available day for this task
            freq[tasks[i]] = days + space + 1;
        }

        return days;
    }
};


