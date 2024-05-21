class Solution {
public:

void solve( vector<int> nums,int index, vector<int> output,vector<vector<int>> &ans){
    if(index>=nums.size()){
        ans.push_back(output);
        return ;
    }

    solve(nums,index + 1,output,ans);
    int element = nums[index];
    output.push_back(element);
    solve(nums,index+1,output,ans);
    output.pop_back();
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        vector <int> output;
        solve(nums,index,output,ans);
        return ans;
    }
};