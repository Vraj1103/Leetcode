class Solution {
public:
    int countStudents(vector<int>& nums, vector<int>& sw) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int count = 0;
        for(auto &x:nums){
            mp1[x]++;
        }

        for(auto &x:sw){
            mp2[x]++;
        }

        if(mp1==mp2)return 0;
        else{
            for(int i = 0;i<nums.size();i++){
                if(nums[i]!=sw[i])count++;
                else continue;
            }
        }
        return count;
    }
};