class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int l=0,r=0;
        int ans=0;
        int n=s.size();
        int sum=0;
        for(;r<n;r++){
           if(s[r]=='T') sum+=1;
           while((r-l+1)-sum>k){
            if(s[l]=='T'){
                sum--;
            }
            l++;
           }
           ans=max(ans,r-l+1);
        }
sum=0;
r=0,l=0;
         for(;r<n;r++){
           if(s[r]=='F') sum+=1;
           while((r-l+1)-sum>k){
            if(s[l]=='F'){
                sum--;
            }
            l++;
           }
           ans=max(ans,r-l+1);
        }
        return ans;
    }
};