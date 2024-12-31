class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        unordered_set<int>travel(days.begin(),days.end());
        vector<int>dp(days.back()+1,0);
        for(int i=1;i<=days.back();i++){
            if(travel.find(i)==travel.end()) dp[i]=dp[i-1];
            else{
                dp[i]=min({cost[0]+dp[max(0,i-1)],cost[1]+dp[max(0,i-7)],cost[2]+dp[max(0,i-30)]});
            }

        }
        return dp[days.back()];
    }
};