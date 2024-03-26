class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto& x : nums) {
            if (x < 0)
                x = 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            if (index >= 0 && index < nums.size()) {
                if (nums[index] > 0) {
                    nums[index] *= -1;
                }
                if (nums[index] == 0) {
                    nums[index] = -1 * (nums.size() + 1);
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0)
                return i + 1;
        }
        return nums.size() + 1;
    }
};