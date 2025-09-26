class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;

        int i=0;
        int n=nums.size();
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
             ans=max(ans,sum);
            if(sum<0){
                sum=0;
                i=j+1;
            }
           
        }
        return ans;
    }
};