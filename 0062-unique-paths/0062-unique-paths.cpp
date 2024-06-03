class Solution {
public:
    int dp[101][101];
    int solve(int M, int N, int m, int n) {
        if (M > m - 1 || N > n - 1)
            return 0;
        if (M == m - 1 || N == n - 1)
            return 1;
        if (dp[M][N] != -1)
            return dp[M][N];
        int ans = solve(M + 1, N, m, n);
        ans += solve(M, N + 1, m, n);
        return dp[M][N] = ans;
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m, n);
    }
};