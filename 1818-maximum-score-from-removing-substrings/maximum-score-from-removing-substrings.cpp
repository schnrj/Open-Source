class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        int ans=0;
        if(x>y){
            string temp;
           for(int i=0;i<s.size();i++){
                if(!temp.empty()&&temp.back()=='a'&&s[i]=='b'){
                    ans+=x;
                    temp.pop_back();

                }
                else temp+=s[i];
        }
        string temp2;
        for(int i=0;i<temp.size();i++){
                if(!temp2.empty()&&temp2.back()=='b'&&temp[i]=='a'){
                    ans+=y;
                    temp2.pop_back();

                }
                else temp2+=temp[i];
        }
        }
        else{
             string temp;
           for(int i=0;i<s.size();i++){
                if(!temp.empty()&&temp.back()=='b'&&s[i]=='a'){
                    ans+=y;
                    temp.pop_back();

                }
                else temp+=s[i];
        }
        string temp2;
        for(int i=0;i<temp.size();i++){
                if(!temp2.empty()&&temp2.back()=='a'&&temp[i]=='b'){
                    ans+=x;
                    temp2.pop_back();

                }
                else temp2+=temp[i];
        }

        }
        return ans;
    }
};