class Solution {
public:
    vector<vector<int>> generate(int nums) {
        vector<vector<int>>ans(nums);
        for(int i=0;i<nums;i++){
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
       
    }
};