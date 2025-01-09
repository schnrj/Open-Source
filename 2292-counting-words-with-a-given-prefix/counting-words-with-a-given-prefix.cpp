class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        int l=pref.size();
        for(int i=0;i<words.size();i++){
            string sachu=words[i];
            if(sachu.substr(0,l)==pref) ans++;
            
        }
        return ans;
    }
};