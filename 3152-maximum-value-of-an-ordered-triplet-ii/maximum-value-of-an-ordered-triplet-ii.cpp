class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>pm(n,0);
        vector<int>sm(n,0);
        int x=nums[0];
        pm[0]=x;
        for(int i=1;i<n;i++){
            x=max(x,nums[i]);
            pm[i]=x;
        }
        int y=nums[n-1];
        sm[n-1]=y;
        for(int i=n-2;i>=0;i--){
            y=max(y,nums[i]);
           sm[i]=y;
        }
        long long sachu=INT_MIN;
        for(int i=1;i<n-1;i++){
            long long ans=((long long)pm[i-1]-(long long)nums[i])*(long long)sm[i+1];
            if(ans<0){
                ans=0;
            }
            sachu=max(sachu,ans);
        }
return sachu;
    }
};