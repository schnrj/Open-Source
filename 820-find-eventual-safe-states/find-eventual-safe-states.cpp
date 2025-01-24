class Solution {
public:
    bool cycle(int i, unordered_map<int, vector<int>>& adj, vector<bool>& inRecStack, vector<bool>& vis) {
        vis[i] = true;
        inRecStack[i] = true;
        for (auto v : adj[i]) {
            if (!vis[v] && cycle(v, adj, inRecStack, vis)) {
                return true;
            } else if (inRecStack[v]) {
                return true;
            }
        }
        inRecStack[i] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<bool> vis(graph.size(), false);
        vector<bool> inRecStack(graph.size(), false);

        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i]) {
                cycle(i, adj, inRecStack, vis);
            }
        }

        vector<int> ans;
        for (int i = 0; i < inRecStack.size(); i++) {
            if (!inRecStack[i]) ans.push_back(i);
        }
        return ans;
    }
};
