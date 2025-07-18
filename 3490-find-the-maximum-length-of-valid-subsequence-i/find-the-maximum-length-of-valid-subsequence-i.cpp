class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int e=0,o=0,alt=1;
        bool expect_even=false;
        if(nums[0]%2!=0){
            o++;
            expect_even=true;
        }
        else {
            e++;

        }
        for(int i=1;i<nums.size();i++){
            int v=nums[i];
           if(expect_even&&v%2==0){
            alt++;
            e++;
            expect_even=!expect_even;
           }
           else if(!expect_even&&v%2!=0){
            alt++;
            o++;
            expect_even=!expect_even;
           }
           else if(expect_even&&v%2!=0){
            o++;
           }
           else if(!expect_even&&v%2==0){
            e++;
           }




        }
        return max({e,o,alt});
    }
};