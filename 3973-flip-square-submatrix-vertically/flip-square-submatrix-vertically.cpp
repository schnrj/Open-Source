class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int lr = x + k - 1;
        int lc = y + k;    
        
        for (int i = 0; i < k / 2; i++) {
            int tr = x + i;
            int br = lr - i;
            for (int j = y; j < lc; j++) {
                swap(grid[tr][j], grid[br][j]);
            }
        }
        return grid;
    }
};
