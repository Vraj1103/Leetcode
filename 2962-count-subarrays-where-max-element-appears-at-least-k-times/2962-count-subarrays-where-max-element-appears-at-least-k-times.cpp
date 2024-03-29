class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = INT_MIN;
        for (auto x : nums) {
            mx = max(mx, x);
        }

        long long count = 0, l = 0, r = 0;
        long long freq = 0;

        while (r < nums.size() && l <= r) {
            int curr = nums[r];
            if (curr == mx) {
                freq++;
            }
            while (freq >= k) {
                if (nums[l] == curr)
                    freq--;
                l++;
                count += nums.size() - r;
            }
            r++;
        }
        return count;
    }
};