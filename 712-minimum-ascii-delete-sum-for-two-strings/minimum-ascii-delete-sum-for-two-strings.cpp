class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, int m, int n, string& s1, string& s2) {
        if(i == m) {
            int sum = 0;
            for(int k = j; k < n; k++) sum += int(s2[k]);
            return sum;
        }
        if(j == n) {
            int sum = 0;
            for(int k = i; k < m; k++) sum += int(s1[k]);
            return sum;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) 
            return dp[i][j] = solve(i+1, j+1, m, n, s1, s2);

        int first = int(s1[i]) + solve(i+1, j, m, n, s1, s2);
        int second = int(s2[j]) + solve(i, j+1, m, n, s1, s2);

        return dp[i][j] = min(first, second);
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        dp.assign(m, vector<int>(n, -1));
        return solve(0, 0, m, n, s1, s2);
    }
};
