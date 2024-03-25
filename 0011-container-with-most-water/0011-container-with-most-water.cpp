class Solution {
public:
    int maxArea(vector<int>& height) {
        int area  = 0;
        int s=0,e=height.size()-1;

        while(s<e){
            int area_temp = abs(e-s)*min(height[s],height[e]);
            area = max(area,area_temp);
            if(height[s]<height[e])s++;
            else e--;
        }
        return area;
    }
};