class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int ans=0;
        int one=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                one++;
                ans=max(ans,one);
            }
            else{
                one=0;
            }
        }
        return ans ;
    }
};