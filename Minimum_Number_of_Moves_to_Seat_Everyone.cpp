
auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int sum = 0;
        for(int i =0 ; i < seats.size(); i++){
            sum+= abs(seats[i] - students[i]);
        }
        return sum;
    }
};