class Solution {
public:
    int minOperations(vector<int>& nums, int x) {//start 
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int rem = total - x;
        if (rem == 0)
            return nums.size();

        int length = maxSubArrayLen(rem, nums);

        if (length == 0)
            return -1;
        return n - length;
    }

    int maxSubArrayLen(int k, vector<int>& A) {
        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp; 
        mp[0] = -1;

        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (mp.find(sum - k) != mp.end())
                res = max(res, i - mp[sum - k]);

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return res;
    }
};