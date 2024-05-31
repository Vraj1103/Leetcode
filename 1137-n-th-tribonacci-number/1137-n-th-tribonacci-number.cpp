class Solution {
public:
    int solve(int n, vector<int>& ans) {
        if (ans[n] != -1)
            return ans[n];
        else {
            if (n == 0)
                return 0;
            if (n == 1 || n == 2)
                return 1;

            return ans[n] = solve(n - 1, ans) + solve(n - 2, ans) +
                            solve(n - 3, ans);
        }
    }

    int tribonacci(int n) {

        vector<int> ans(n + 1, -1);
        return solve(n, ans);
    }
};