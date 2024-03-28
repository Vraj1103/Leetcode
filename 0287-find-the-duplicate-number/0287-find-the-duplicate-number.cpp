class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup = 0;

        for(int i = 0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            if(nums[index]<0){
                return index+1;
            }
            if(index>0 && index<nums.size()){
                nums[index]*=-1;
            }
        }
        return -1;
    }
};