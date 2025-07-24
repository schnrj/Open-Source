class Solution {
public:
    vector<vector<int>> tree;
    vector<int> in, out, xorSub;
    int timer = 0;

    int dfs(int node, int parent, const vector<int>& nums) {
        int x = nums[node];
        in[node] = timer++;
        for (int nei : tree[node]) {
            if (nei != parent) {
                x ^= dfs(nei, node, nums);
            }
        }
        out[node] = timer++;
        xorSub[node] = x;
        return x;
    }

    bool isAncestor(int u, int v) {
        return in[u] < in[v] && out[v] < out[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.resize(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        in.resize(n);
        out.resize(n);
        xorSub.resize(n);

        int total = dfs(0, -1, nums);

        int res = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j;
                if (isAncestor(a, b)) {
                    int x = xorSub[b];
                    int y = xorSub[a] ^ xorSub[b];
                    int z = total ^ xorSub[a];
                    res = min(res, max({x, y, z}) - min({x, y, z}));
                } else if (isAncestor(b, a)) {
                    int x = xorSub[a];
                    int y = xorSub[b] ^ xorSub[a];
                    int z = total ^ xorSub[b];
                    res = min(res, max({x, y, z}) - min({x, y, z}));
                } else {
                    int x = xorSub[a];
                    int y = xorSub[b];
                    int z = total ^ x ^ y;
                    res = min(res, max({x, y, z}) - min({x, y, z}));
                }
            }
        }

        return res;
    }
};
