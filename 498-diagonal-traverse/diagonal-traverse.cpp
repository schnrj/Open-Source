class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            int col = i;
            for (int j = 0; j < m && col >= 0; j++, col--) {
                temp.push_back(mat[j][col]);
            }
            if (count % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            count++;
            ans.insert(ans.end(), temp.begin(), temp.end());
        }

        for (int i = 1; i < m; i++) {
            vector<int> temp;
            int row = i;
            int col = n - 1;
            for (; row < m && col >= 0; row++, col--) {
                temp.push_back(mat[row][col]);
            }
            if (count % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            count++;
            ans.insert(ans.end(), temp.begin(), temp.end());
        }

        return ans;
    }
};
