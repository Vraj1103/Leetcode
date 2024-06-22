class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (auto& i : nums) {
            i = i % 2;
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};