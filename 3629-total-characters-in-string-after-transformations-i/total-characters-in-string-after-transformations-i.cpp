class Solution {
public:
 const int MOD=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int>cnt(26,0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }
        for(int i=0;i<t;i++){
            vector<int>sachu(26,0);
            sachu[0]=cnt[25];
            sachu[1]=(cnt[25]+cnt[0])%MOD;
            for(int i=2;i<26;i++){
                sachu[i]=cnt[i-1];
            }
            cnt=move(sachu);
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans%MOD+cnt[i]%MOD)%MOD;
        }
        return ans;
        
    }
};