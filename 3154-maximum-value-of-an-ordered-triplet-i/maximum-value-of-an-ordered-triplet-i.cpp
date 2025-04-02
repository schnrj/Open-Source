class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long x=INT_MIN;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    
                    long long y=((long long)nums[i]-(long long)nums[j])*(long long)nums[k];
                    // long long y=(long long)(nums[i]*nums[k])-(long long)(nums[j]*nums[k]);
                    if(y<0){
                        y=0;
                    }
                    x=max(x,y);

                }
            }
        }
        return x;
    }
};