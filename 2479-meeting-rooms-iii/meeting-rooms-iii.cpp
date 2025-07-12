class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> froom;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> oroom;

        for (int i = 0; i < n; i++) {
            froom.push(i);
        }

        for (int i = 0; i < meetings.size(); i++) {
            long long stime = meetings[i][0];
            long long etime = meetings[i][1];
            long long duration = etime - stime;

            while (!oroom.empty() && oroom.top().first <= stime) {
                int room = oroom.top().second;
                froom.push(room);
                oroom.pop();
            }

            if (!froom.empty()) {
                int room = froom.top();
                froom.pop();
                mp[room]++;
                oroom.push({etime, room});
            } else {
                auto [free_time, room] = oroom.top();
                oroom.pop();
                mp[room]++;
                long long new_end = free_time + duration;
                oroom.push({new_end, room});
            }
        }

        int maxi = INT_MIN;
        int ans = -1;
        for (auto p : mp) {
            if (p.second > maxi) {
                maxi = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};
