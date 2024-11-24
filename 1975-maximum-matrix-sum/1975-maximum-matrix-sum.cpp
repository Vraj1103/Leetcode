class Solution {
public:
    void maximize_adj(vector<vector<int>>& nums, int i, int j) {
        nums[i][j] = -nums[i][j];
    }

    long long maxMatrixSum(vector<vector<int>>& nums) {
        long long sum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0; 

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                if (nums[i][j] < 0) {
                    maximize_adj(nums, i, j);
                    negativeCount++;
                }
                sum += abs(nums[i][j]);
                minAbsValue = min(minAbsValue, abs(nums[i][j]));
            }
        }

        if (negativeCount % 2 != 0) {
            sum -= 2 * minAbsValue;
        }

        return sum;
    }
};
