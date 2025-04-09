class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> cost(n, INT_MAX);
        vector<int> t(n, INT_MAX);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        cost[0] = passingFees[0];
        t[0] = 0;
        pq.push({cost[0], 0, 0});
        
        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            int c = cur[0];
            int node = cur[1];
            int timeSpent = cur[2];
            
            if (node == n - 1) return c;
            
            for (auto& [child, edgeTime] : adj[node]) {
                int newTime = timeSpent + edgeTime;
                int newCost = c + passingFees[child];
                
                if (newTime <= maxTime) {
                    
                    if (cost[child] > newCost) {
                        cost[child] = newCost;
                        t[child] = newTime;
                        pq.push({cost[child], child, timeSpent + edgeTime});
                    }
                    else if (t[child] > newTime) {
                        t[child] = newTime;
                        pq.push({newCost, child, newTime});
                    }
                }
            }
        }
        
        return -1;
    }
};
