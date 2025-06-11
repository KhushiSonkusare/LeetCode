class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, tens = 0;
        for(int i = 0; i< bills.size(); i++){
            if(bills[i] == 5) five++;
            else if(bills[i] == 10){
                tens++;
                if(five) five--;
                else return false;
            }else{
                if(five && tens) {five--; tens--;}
                else if(five>=3) five-=3;
                else return false;
            }
        }

        return true;
    }
};