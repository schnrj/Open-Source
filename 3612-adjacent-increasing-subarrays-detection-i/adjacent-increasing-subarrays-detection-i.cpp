class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
       int n = nums.size();

       int inc=1,pinc=0;
       for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]){
            inc++;
        }
        else{
            pinc=inc;
            inc=1;
        }
        if(inc>=2*k||(inc>=k&&pinc>=k)) return true;
       }
       return false;
    }
};