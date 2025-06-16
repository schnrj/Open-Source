class Solution {
public:
    int maximumDifference(vector<int>& prices) {
        if(is_sorted(prices.begin(),prices.end(),greater<int>())) return -1;
        int buy=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(buy>prices[i]){
                buy=prices[i];
            }
            ans=max(ans,prices[i]-buy);
        }
        return ans;
    }
};