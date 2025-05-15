class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
    //   if(words)
    int f=groups[0];
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(f!=groups[i]){
               f=groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    } 
};