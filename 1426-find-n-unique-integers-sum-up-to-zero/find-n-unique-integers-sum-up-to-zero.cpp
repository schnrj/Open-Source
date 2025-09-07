class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1) return {0};
        vector<int>ans(n);
        if(n%2==0){
            int j=0;
            for(int i=(-1)*(n/2);i<0;i++){
                ans[j++]=i;
            }
            // ans[j++]=0;
            for(int i=1;i<=(n/2);i++){
                ans[j++]=i;
            }



        }
        else{
             int j=0;
            for(int i=(-1)*(n/2);i<=(n/2);i++){
                ans[j++]=i;
            }
            
        }
        return ans;
    }
};