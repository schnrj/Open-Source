class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]].first=i;
            }
            else{
                mp[s[i]].second=i;
            }
        }
        for(auto p:mp){
            cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<" ";
        }
        vector<int>pre(s.size(),0);
        map<char,int>check;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(check.find(s[i])==check.end()){
                count++;
                check[s[i]]=i;
            }
            pre[i]=count;
        }
        cout<<endl;
        for(int i=0;i<pre.size();i++) cout<<pre[i]<<" ";
        // return 1;
        int ans=0;
        // for(auto p:mp){
        //     int l=p.second.first;
        //     int r=p.second.second;
        //     // ans+=(pre[r]-pre[l]+1);
        //     if(r>l) ans+=(pre[r]-pre[l]+1);

        // }
        for(char ch='a';ch<='z';ch++){
               if(mp.find(ch)!=mp.end()){
                 int l=mp[ch].first;
            int r=mp[ch].second;
            set<char>sachu;
           for(int j=l+1;j<=r-1;j++){
               sachu.insert(s[j]);
           }
           ans+=sachu.size();
               }
        }
        return ans;
    }
};