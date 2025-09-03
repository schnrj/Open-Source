class Solution {
public:

int count(string &s1,string &s2){
       int save[26][26] = {};
        int ops = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) continue;

            if (save[s2[i] - 'a'][s1[i] - 'a'] > 0) {
                save[s2[i] - 'a'][s1[i] - 'a']--;
            } else {
                save[s1[i] - 'a'][s2[i] - 'a']++;
                ops++;
            }
        }

        return ops;  
}

int solve(int i,string &s1,string &s2,vector<int>&dp){
    if(i==s1.size()){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int mini=INT_MAX;
    for(int j=i;j<s1.size();j++){
        string new1=s1.substr(i,j-i+1);
        string new2=s2.substr(i,j-i+1);

        int op1=count(new1,new2);
        
        reverse(new1.begin(),new1.end());
        int op2=count(new1,new2);
        
        int remain=solve(j+1,s1,s2,dp);
      
      mini=min(mini,remain+min(op1,op2+1));



    }
    return dp[i]=mini;
}
    int minOperations(string word1, string word2) {
        int n=word1.size();
        vector<int>dp(n,-1);

        return solve(0,word1,word2,dp);
        
    }
};