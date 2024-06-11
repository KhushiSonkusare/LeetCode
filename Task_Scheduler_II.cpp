

auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> freq;
        long long days = 0;

        for (int i = 0; i < tasks.size(); i++) {
            if (freq.find(tasks[i]) == freq.end() || days >= freq[tasks[i]]) {
                days++;
            } else {
                days = freq[tasks[i]];
            }
            freq[tasks[i]] = days + space + 1;
        }

        return days;
    }
};


