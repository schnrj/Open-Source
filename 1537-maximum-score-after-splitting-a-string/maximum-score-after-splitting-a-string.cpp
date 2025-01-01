class Solution {
public:
    int maxScore(string s) {
        vector<int>z(s.size(),0);
        
        vector<int>o(s.size(),0);
        int count=0;
        int countt=0;
        for(int i=0;i<s.size();i++){
             if(s[i]=='0'){
                count++;
             }
             z[i]=count;
             if(s[s.size()-i-1]=='1'){
                countt++;
             }
             o[s.size()-i-1]=countt;
        }
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            int one;
            if(s[i]=='1'){
                one=o[i+1];
            }
            else one=o[i];
            int sachu=0;
            sachu+=z[i]+one;
            ans=max(ans,sachu);
        
        }
        return ans;
    }
};