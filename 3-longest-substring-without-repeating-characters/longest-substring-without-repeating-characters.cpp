class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0,r=0;
        int ans=0;
        int n=s.size();
        for(;r<n;r++){
            mp[s[r]]++;
            while(mp[s[r]]>1&&l<n){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};