class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<int>sub;
        // for(auto x:nums){
        //     if(sub.empty()||sub[sub.size()-1]<x){
        //         sub.push_back(x);
        //     }
        //     else{
        //         auto it=lower_bound(sub.begin(),sub.end(),x);
        //         *it=x;
        //     }
        // }
        // return sub.size();
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            int maxi=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    // maxi=dp[j];
                    // if(dp[j]>maxi) maxi=dp[j];
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            // dp[i]=maxi+1;
        }
        return *max_element(dp.begin(),dp.end());
    }
};