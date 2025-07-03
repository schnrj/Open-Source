class Solution {
public:
    char kthCharacter(int k) {
        vector<char>v(26);
        // char ch='a';
        // for(int i=0;i<26;i++){
        //   v[i]=ch;
        //   ch++;
        // //   cout<<ch<<" ";
        // }
        string ans="a";
        while(ans.size()<=k){
            string temp=ans;
            for(int i=0;i<temp.size();i++){
                if(temp[i]=='z'){
                    temp[i]='a';
                }
                else temp[i]++;
            }
            ans+=temp;
        }
        return ans[k-1];
    }
};