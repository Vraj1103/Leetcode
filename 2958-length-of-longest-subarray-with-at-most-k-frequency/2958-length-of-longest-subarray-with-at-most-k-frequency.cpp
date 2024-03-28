class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = INT_MIN;
        int l = 0, r = 0;
        while (r < nums.size()) {
            mp[nums[r]]++;
            while (l<r && mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            r++;
            ans = max(ans, r - l);
        }
        return ans;
    }
};