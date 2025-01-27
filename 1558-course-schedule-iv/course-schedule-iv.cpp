class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<int>> sachu(n, vector<int>(n, INT_MAX));
        
        for (int i = 0; i < n; ++i) {
            sachu[i][i] = 0;
        }

        for (const auto& edge : p) {
            sachu[edge[0]][edge[1]] = 1;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (sachu[i][k] != INT_MAX && sachu[k][j] != INT_MAX) {
                        sachu[i][j] = min(sachu[i][j], sachu[i][k] + sachu[k][j]);
                    }
                }
            }
        }

        vector<bool> ans(q.size());
        for (int i = 0; i < q.size(); ++i) {
            ans[i] = (sachu[q[i][0]][q[i][1]] != INT_MAX);
        }

        return ans;
    }
};
