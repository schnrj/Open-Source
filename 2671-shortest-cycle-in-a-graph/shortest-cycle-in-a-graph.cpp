class Solution {
public:
    int ans = INT_MAX; 

    void bfs(vector<vector<int>>& graph, int i, vector<bool>& vis) {
        queue<pair<int, int>> q;
        vector<int> dist(graph.size(), 0);

        q.push({i, -1});
        vis[i] = true;
        
        while (!q.empty()) {
            int cur = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto v : graph[cur]) { 
                if (!vis[v]) {
                    vis[v] = true;
                    dist[v] = dist[cur] + 1;
                    q.push({v, cur});
                }
                else if (v != par) { 
                    ans = min(ans, dist[cur] + dist[v] + 1);
                }
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            bfs(graph, i, vis);
        }
        
        return (ans == INT_MAX ? -1 : ans);
    }
};
