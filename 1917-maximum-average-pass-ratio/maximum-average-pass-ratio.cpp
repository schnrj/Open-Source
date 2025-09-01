class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int,int>>> pq; 
        
        for (auto &c : classes) {
            int p = c[0], t = c[1];
            double gain = (double)(p+1)/(t+1) - (double)p/t;
            pq.push({gain, {p, t}});
        }
        
        while (extraStudents--) {
            auto [gain, p] = pq.top();
            pq.pop();
            int newP = p.first + 1;
            int newT = p.second + 1;
            double newGain = (double)(newP+1)/(newT+1) - (double)newP/newT;
            pq.push({newGain, {newP, newT}});
        }
        
        double ans = 0.0;
        while (!pq.empty()) {
            auto [gain, p] = pq.top();
            pq.pop();
            ans += (double)p.first / p.second;
        }
        
        return ans / classes.size();
    }
};
