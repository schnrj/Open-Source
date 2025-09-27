class Solution {
public:
    vector<int> memo;
    int n;
    
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n; 
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (array[mid][0] >= currentJobEnd) { 
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
    
    int solve(vector<vector<int>>& array, int i) {
        if (i >= n) return 0;
        if (memo[i] != -1) return memo[i];
        
        int next = getNextIndex(array, i + 1, array[i][1]);
        
        int take = array[i][2] + solve(array, next);
        int skip = solve(array, i + 1);
        
        return memo[i] = max(take, skip);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memo.assign(n, -1); 
        
        vector<vector<int>> array(n, vector<int>(3, 0)); 
        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        
        sort(array.begin(), array.end(), [&](auto& a, auto& b) {
            return a[0] < b[0];
        });
        
        return solve(array, 0);
    }
};
