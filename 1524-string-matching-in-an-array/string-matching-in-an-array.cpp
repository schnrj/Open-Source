class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
       set<string>sachu;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i==j) continue;
                else{
                    string sub=words[i];
                    if(words[j].find(sub)!=string::npos){
                        sachu.insert(sub);
                    }
                }
            }
        }
        vector<string>ans(sachu.begin(),sachu.end());
        return ans;
    }
};