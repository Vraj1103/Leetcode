class Solution {
public:
    int dp[101][101];
    int solve(int M,int N,int m,int n,vector<vector<int>>& g){
        if(M>m-1 || N>n-1 ||g[M][N]==1)return 0;
        if(M==m-1 && N==n-1)return 1;
        if(dp[M][N]!=-1)return dp[M][N];
        int ans = solve(M+1,N,m,n,g);
        ans+=solve(M,N+1,m,n,g);
        return dp[M][N]=ans;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,g.size(),g[0].size(),g);
    }
};