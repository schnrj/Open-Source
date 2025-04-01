class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || n == k) return 0;
        vector<int>sachu;
        for (int i = 0; i < n-1; i++)
        {
            sachu.push_back(weights[i] + weights[i+1]);
        }
        sort(sachu.begin(),sachu.end());
        long long mins = 0, maxs = 0;
        for (int i = 0; i < k-1; i++)
        {
            mins +=sachu[i];
            maxs +=sachu[n-2-i];
        }
        return maxs - mins;
    }
};