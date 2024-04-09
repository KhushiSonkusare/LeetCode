class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int max = 0;
        while(i<j){
            int temp;
            if(height[i]<height[j]){
                  temp =(j-i)*height[i];  
                 i++;
            }  
            else {
                 temp =(j-i)*height[j];
                j--;
            }
            if(temp>max)max=temp;
            
        }
        return max;
    }
};