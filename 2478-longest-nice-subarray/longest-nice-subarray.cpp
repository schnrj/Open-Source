class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0;
        int x=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            while((x&nums[i])!=0){
                x=x^nums[j];
                j++;
            }
            x=x|nums[i];
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};