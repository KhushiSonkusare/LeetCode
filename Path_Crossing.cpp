#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<string> visited;
        visited.insert("0,0");

        for (char direction : path) {
            if (direction == 'N') {
                y++;
            } else if (direction == 'S') {
                y--;
            } else if (direction == 'E') {
                x++;
            } else if (direction == 'W') {
                x--;
            }

            string current_pos = to_string(x) + "," + to_string(y);
            if (visited.find(current_pos) != visited.end()) {
                return true; 
            } else {
                visited.insert(current_pos);
            }
        }

        return false; 
    }
};
