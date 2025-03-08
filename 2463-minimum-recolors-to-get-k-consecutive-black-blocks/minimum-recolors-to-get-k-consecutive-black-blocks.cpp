class Solution {
public:
    int minimumRecolors(string blocks, int k) {
      
        int black=0;
        int i;
        for( i=0;i<k;i++){
            if(blocks[i]=='B') black++;
        }
        int ans=k-black;
        for(;i<blocks.size();i++){
           if(blocks[i]=='B') black++;
           if(blocks[i-k]=='B') black--;
           ans=min(ans,k-black);
            
        }
        return ans;
    }
};