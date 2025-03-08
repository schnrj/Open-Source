class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        for(int i=0;i<=blocks.size()-k;i++){
            string s=blocks.substr(i,k);
            int count=0;
            for(int j=0;j<s.size();j++){
                if(s[j]=='W') count++;
            }
            ans=min(ans,count);
        }
        
        return ans;
    }
};