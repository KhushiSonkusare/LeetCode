class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        while(tickets[k]!=0){
            int min = 9999;
            int count = 0;
            for(int i = 0; i<tickets.size(); i++){
                if(tickets[i]>0){
                    count++;
                    if(tickets[i]<min){
                        min = tickets[i];
                    }
                }
            }
            time+=min*count;
            for(int i = 0; i<tickets.size(); i++){
                tickets[i]-= min;
            }
        }
        return time;
    }
};