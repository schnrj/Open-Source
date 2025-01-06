class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size());
        for(int i=0;i<boxes.size();i++){
            int count=0;
            for(int j=0;j<boxes.size();j++){
                if(j==i) continue;
                else{
                     if(boxes[j]=='1'){
                        count+=(abs(j-i));
                     }
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};