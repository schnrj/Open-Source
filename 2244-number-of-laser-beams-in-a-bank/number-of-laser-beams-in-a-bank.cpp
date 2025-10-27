class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size()==1) return 0;
        vector<int>ans;
        for(int i=0;i<bank.size();i++){
            string temp=bank[i];
            int count=0;
            for(auto ch:temp){
                if(ch=='1') count++;
            }
            if(count!=0) ans.push_back(count);

        }
       
       if(ans.size()==0||ans.size()==1) return 0;

       int total=0;
       for(int i=0;i<ans.size()-1;i++){
        total+=(ans[i]*ans[i+1]);
       }
       return total;

    }
};