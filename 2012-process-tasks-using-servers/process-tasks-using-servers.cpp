class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> free;
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> occ;

        for (int i = 0; i < servers.size(); i++) {
            free.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            
            while (!occ.empty() && occ.top().first <= time) {
                free.push(occ.top().second);
                occ.pop();
            }

            
            if (free.empty()) {
                time = occ.top().first;
                while (!occ.empty() && occ.top().first <= time) {
                    free.push(occ.top().second);
                    occ.pop();
                }
            }

            auto server = free.top(); free.pop();
            ans.push_back(server.second);
            occ.push({time + tasks[i], server});
        }

        return ans;
    }
};
