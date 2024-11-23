class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& nums) {
        int ans = 0;
        unordered_map<string, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            string temp = "";
            for (int j = 0; j < nums[i].size(); j++) {
                if (nums[i][j] == nums[i][0]) {
                    temp += "T";
                } else
                    temp += "F";
            }
            mp[temp]++;
        }

        for (auto i : mp) {
            ans = max(ans, i.second);
        }
        return ans;
    }
};