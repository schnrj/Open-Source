class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int>q;
        q.push(0);
        for(int i=1;i<s.size();i++){

            if(s[i]=='0'){
                while(!q.empty()&&q.front()<i-maxJump) q.pop();
                if(q.empty()) return false;
                int prev=q.front();
                if(prev+minJump<=i&&i<=prev+maxJump){
                    q.push(i);
                    if(i==s.size()-1) return true;
                }
            }

        }
        return false;
    }
};