class Solution {
public:
    int solve(int i, int j, string &s1,string &s2,vector<vector<int>>&dp){

        if(i==s1.size()&&j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==s1.size()){
            return s2.size()-j;
        }
        if(j==s2.size()){
            return s1.size()-i;
        }
        
        if(s1[i]==s2[j]){
           return solve(i+1,j+1,s1,s2,dp);
        }
        int ans=min({1+solve(i+1,j,s1,s2,dp),1+solve(i,j+1,s1,s2,dp)});
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {

int m=word1.size();
int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

       return solve(0,0,word1,word2,dp);
        
    }
};