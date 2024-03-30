class Solution {
public:
    int atk(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0, r = 0, ans = 0;
        while (r < nums.size()) {
            mp[nums[r]]++;
            while (mp.size() > k && l <= r) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a = atk(nums, k);
        int b = atk(nums, k - 1);
        return (a - b);
    }
};