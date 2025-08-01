class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens=0, twen = 0;
        for(int i = 0; i< bills.size(); i++){
            if(bills[i] == 5){
                fives++;
            }
            else if(bills[i] == 10){
                tens++;
                if(fives) fives--;
                else return false;
            }
            else{
                twen++;
                if(tens && fives){tens--; fives--;}
                else if(fives >= 3) fives-= 3;
                else return false;
            }

        }

        return true;
    }
};