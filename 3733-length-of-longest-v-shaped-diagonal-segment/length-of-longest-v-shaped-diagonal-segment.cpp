class Solution {
public:
    int m, n;
    int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int memo[501][501][4][2];

    int dfs(vector<vector<int>>& grid, int cx, int cy, int direction, bool turn, int target) {
        int nx = cx + dirs[direction][0];
        int ny = cy + dirs[direction][1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
            return 0;
        }
        if (memo[nx][ny][direction][turn] != -1) {
            return memo[nx][ny][direction][turn];
        }
        int maxStep = dfs(grid, nx, ny, direction, turn, 2 - target);
        if (turn) {
            maxStep = max(maxStep, dfs(grid, nx, ny, (direction + 1) % 4, false, 2 - target));
        }
        memo[nx][ny][direction][turn] = maxStep + 1;
        return maxStep + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(memo, -1, sizeof(memo));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; ++direction) {
                        res = max(res, dfs(grid, i, j, direction, true, 2) + 1);
                    }
                }
            }
        }
        return res;
    }
};