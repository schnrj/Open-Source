class Solution {
public:
    string clearDigits(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>=48&&s[i]<=58){
                count++;
            }
        }
        while(count--){
            for(int i=1;i<s.size();i++){
                if(s[i]>=48&&s[i]<=58){
                    s.erase(i,1);
                    s.erase(i-1,1);
                    break;
                }
            }
        }
        return s;
    }
};