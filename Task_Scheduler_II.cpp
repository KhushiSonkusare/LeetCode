#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, int> freq;
        long long days = 0;
        for (int i = 0; i < tasks.size(); i++) {
            auto it = freq.find(tasks[i]);
            if (it == freq.end()) {
                days++;
                for (auto& pair : freq) {
                    pair.second++;
                }
                freq[tasks[i]] = 0;
            } else {
            if(it->second <= space ){
                while (it->second <= space ) {
                    days++;
                    for (auto& pair : freq) {
                        pair.second++;
                    }
                }
              }else{
                days++;
                for (auto& pair : freq) {
                        pair.second++;
                    }
              }       
                
                freq[tasks[i]] = 0;
            }
            
        }
        return days;
    }
};


