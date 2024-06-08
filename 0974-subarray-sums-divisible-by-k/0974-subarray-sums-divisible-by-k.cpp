class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> mp;
        int count = 0;
        mp[0] = 1;
        for (int i : nums) {
            sum += i;
            int temp = sum % k;
            if (temp < 0)
                temp += k;
            if (mp.find(temp) != mp.end()) {
                count += mp[temp];
                mp[temp]++;
            } else {
                mp[temp]++;
            }
        }
        return count;
    }
};