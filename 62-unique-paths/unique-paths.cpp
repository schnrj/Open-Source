

class Solution {
public:
    int f(int i, int j, int m, int n,vector<vector<int>>& memo) {
       
        if (i == m - 1 && j == n - 1) {
            return 1; 
        }
        if (i >= m || j >= n) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        memo[i][j] = f(i + 1, j, m, n, memo) + f(i, j + 1, m, n, memo);
        return memo[i][j];
    }

    int uniquePaths(int m, int n) {
       
       vector<vector<int>> memo(m, vector<int>(n, -1));
        return f(0, 0, m, n, memo);
    }
};
