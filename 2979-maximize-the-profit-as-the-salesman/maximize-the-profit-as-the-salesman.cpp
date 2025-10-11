class Solution {
public:
    int bs(int val,vector<int>&nums){
        int l=0,r=nums.size()-1,ans=nums.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>val){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int solve(int i,vector<int>&first,vector<int>&second,vector<vector<int>>& offers,vector<int>&dp){

         if(i>=offers.size()) return 0;
         if(dp[i]!=-1) return dp[i];
        int take=offers[i][2];
        int idx=bs(offers[i][1],first);
        take+=solve(idx,first,second,offers,dp);
        int nottake=solve(i+1,first,second,offers,dp);
        return dp[i]=max(take,nottake);
    }
    int maximizeTheProfit(int m, vector<vector<int>>& offers) {
        int n=offers.size();
        sort(offers.begin(),offers.end());
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({offers[i][0],offers[i][1]});
        }
        sort(v.begin(),v.end());
        vector<int>first(n),second(n);
        for(int i=0;i<n;i++){
            first[i]=v[i].first;
            second[i]=v[i].second;
        }
        vector<int>dp(n,-1);
        return solve(0,first,second,offers,dp);
    }
};