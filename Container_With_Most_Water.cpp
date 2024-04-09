class Solution {
public:
    int maxArea(vector<int>& height) {
        int max= 0;
        int i = 0, j = height.size()-1;
        while(i<height.size() && j>=0){
            if((j-i)*min(height[i],height[j])>=max){
                max =( j-i)*min(height[i],height[j]);
            }
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return max;
    }
};