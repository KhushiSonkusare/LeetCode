#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (auto it = count.begin(); it != count.end(); ++it) {
            int card = it->first;
            int occurences = it->second;
            if (occurences > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (count[card + i] < occurences) {
                        return false;
                    }
                    count[card + i] -= occurences;
                }
            }
        }

        return true;
    }
};
