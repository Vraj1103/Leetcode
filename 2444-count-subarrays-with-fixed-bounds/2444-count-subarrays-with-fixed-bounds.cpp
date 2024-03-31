class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left = -1,right = 0,mini = -1,maxi = -1;
        long long ans = 0;

        while(right<nums.size()){
            if(nums[right]>maxK || nums[right]<minK){
                left = right;
                mini = right;
                maxi = right;
            }
            if(nums[right]==minK){
                mini = right;
            }
            if(nums[right]== maxK){
                maxi = right;
            }
            ans+=(min(maxi,mini)-left);
            right++;
        }
        return ans;
    }
};