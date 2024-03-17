class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;

        while(i<nums.size()){
            if(nums[i][1]<newInterval[0]){
                ans.push_back(nums[i]);
            }
            else if(nums[i][0]>newInterval[1])break;
            else{
                newInterval[0] = min(nums[i][0],newInterval[0]);
                newInterval[1] = max(nums[i][1],newInterval[1]);
            }
            i++;
        }
            ans.push_back(newInterval);
            while(i<nums.size()){
                ans.push_back(nums[i]);
                i++;
            }
            return ans;
    }
};