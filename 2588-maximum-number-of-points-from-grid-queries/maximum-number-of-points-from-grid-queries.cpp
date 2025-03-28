class Solution {
public:
    #define pi pair<int, int>
    #define pii pair<int, pi>

    bool valid(int x, int y, int m, int n) {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        set<int> q(queries.begin(), queries.end());
        unordered_map<int, int> mp;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        pq.push(make_pair(grid[0][0], make_pair(0, 0)));
        vis[0][0] = true;

        vector<int> dir = {-1, 0, 1, 0, -1};
        int count = 0;

        for (auto v : q) {
            while (!pq.empty()) {
                pii curr = pq.top();
                int val = curr.first;
                int x = curr.second.first;
                int y = curr.second.second;
                
                if (val >= v) break;
                
                pq.pop();
                count++;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i];
                    int ny = y + dir[i + 1];

                    if (valid(nx, ny, m, n) && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        pq.push(make_pair(grid[nx][ny], make_pair(nx, ny)));
                    }
                }
            }
            mp[v] = count;
        }

        vector<int> res;
        for (int query : queries)
            res.push_back(mp[query]);
        
        return res;
    }
};
