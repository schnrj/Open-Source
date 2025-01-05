class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>offset(s.size()+1,0);
        for(int i=0;i<shifts.size();i++){
           offset[shifts[i][0]]+=(shifts[i][2]==1)?1:-1;
        offset[shifts[i][1]+1]-=(shifts[i][2]==1)?1:-1;
        }
        int prefix=0;
        vector<char>alpha(26);
        int j=0;
        for(char i='a';i<='z';i++){
            alpha[j++]=i;
        }
        for(int i=0;i<s.size();i++){
            prefix+=offset[i];
            while(prefix<0) prefix+=26;
            int ch=(prefix+(s[i]-'a'))%26;
            s[i]=alpha[ch];
        }
        return s;
    }
};