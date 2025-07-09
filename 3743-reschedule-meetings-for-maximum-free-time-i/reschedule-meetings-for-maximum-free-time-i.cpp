
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size() + 1;
        vector<int> sachu(n);
        sachu[0] = startTime[0];
        int ans = 0, res = 0;
        
        for (int i = 1; i < n - 1; i++) {
            sachu[i] = startTime[i] - endTime[i - 1];
        }
        sachu[n - 1] = eventTime - endTime[n - 2];
        
        for (int i = 0; i <= k && i < n; i++) {
            ans += sachu[i];
        }
        res = max(res,ans);
        
        for (int i = 1; i < n - k; i++) {
            int temp1= sachu[i - 1];
            int temp2=sachu[i+k];
            ans =ans-temp1+temp2;
            
            res = max(res, ans);
        }
        
        return res;
    }
};