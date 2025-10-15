class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int inc=1;
        int pinc=0;
        int ans=1;
        for(int i=1;i<nums.size();i++){
              if(nums[i]>nums[i-1]){
                inc++;
                
              }
              else{
                pinc=inc;
                inc=1;

              }
              ans=max(ans,inc/2);
              ans=max(ans,min(inc,pinc));

        }
        return ans;
    }
};