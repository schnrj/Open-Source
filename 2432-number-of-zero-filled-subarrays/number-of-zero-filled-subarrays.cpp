class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans=0;
        // for(int i=1;i<nums.size();i++){
        //     nums[i]=nums[i]+nums[i-1];
        //     // cout<<nums[i]<<" ";

        // }
        for(int i=0;i<nums.size();i++){
            long long  count=0;
            while(i<nums.size()&&nums[i]==0){
                  i++;
                  count++;
            }
            ans+=(count*(count+1))/2;

        }
        return ans;
        
    }
};