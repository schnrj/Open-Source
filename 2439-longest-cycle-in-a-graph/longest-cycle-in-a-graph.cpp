class Solution {
public:
    int ans = -1;

    void dfs(int u, vector<bool>& vis, vector<bool>& path, vector<int>& graph,vector<int>&count) {
       if(u!=-1){
         vis[u] = true;
        path[u] = true;
        int next = graph[u];

        if (next != -1 && !vis[next]) {
            
            count[next]=count[u]+1;
            dfs(next, vis, path, graph, count);
        } else if (next != -1 && path[next]) {
           
            int x=count[u]-count[next]+1;
            ans = max(ans, x);
        }
        path[u] = false; 
       }
    }

    int longestCycle(vector<int>& graph) {
        int v = graph.size();
        vector<bool> vis(v, false);
        vector<bool> path(v, false);
        vector<int>count(v,1);
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
               
                
                dfs(i, vis, path, graph,count);
            }
        }

        return ans;
    }
};
