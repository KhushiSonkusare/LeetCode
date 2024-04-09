class Solution {
public:
    int maxArea(vector<int>& height) {
        int max= 0;
        for(int i = 0; i<height.size(); i++){
            for(int j = i+1; j<height.size(); j++){
                if((j-i)*min(height[i],height[j])>=max){
                    max = (j-i)*min(height[i],height[j]);
                }
            }
        }
        return max;
    }
};