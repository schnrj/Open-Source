class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int odd=0;
        int even=0;
        for(auto p:mp){
            if(p.second%2!=0) odd++;
            else even++;
        }
       if(odd>k) return false;
       else return true;


    }
};