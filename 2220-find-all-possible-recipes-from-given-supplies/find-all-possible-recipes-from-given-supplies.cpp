class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
    unordered_map<string, vector<string>> graph;
    unordered_set<string> s(sup.begin(), sup.end());
    unordered_map<string, int> indegree;
    
    for (auto& x : rec) indegree[x] = 0;
    
    for (int i = 0; i < rec.size(); i++) {
        for (auto& item : ing[i]) {
            if (!s.count(item)) {
                graph[item].push_back(rec[i]);
                indegree[rec[i]]++;
            }
        }
    }

    queue<string> q;
    for (auto& x : indegree) {
        if (x.second == 0) q.push(x.first);
    }

    vector<string> ans;
    while (!q.empty()) {
        string tmp = q.front();
        q.pop();
        ans.push_back(tmp);
        for (auto& nbr : graph[tmp]) {
            if (--indegree[nbr] == 0) q.push(nbr);
        }
    }
    
    return ans;
}

};