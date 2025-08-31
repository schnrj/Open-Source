class Solution {
public:
    int mod = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int i = 0; i < n; i++) {
            dp[0][i][0] = 1;
            if (grid[0][i] == 1) break;
        }

        for (int i = 0; i < m; i++) {
            dp[i][0][1] = 1;
            if (grid[i][0] == 1) break;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j - 1] == 0) {
                    dp[i][j][0] += (dp[i][j - 1][0] + dp[i][j - 1][1]) % mod;
                    dp[i][j][0] %= mod;
                }
                else {
                    dp[i][j][0] += dp[i][j - 1][1] % mod;
                    dp[i][j][0] %= mod;
                }

                if (grid[i - 1][j] == 0) {
                    dp[i][j][1] += (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
                    dp[i][j][1] %= mod;
                }
                else {
                    dp[i][j][1] += dp[i - 1][j][0] % mod;
                    dp[i][j][1] %= mod;
                }
            }
        }
        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % mod;
    }
};
