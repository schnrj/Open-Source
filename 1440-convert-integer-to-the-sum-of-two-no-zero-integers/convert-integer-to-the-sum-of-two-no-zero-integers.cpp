class Solution {
public:

    bool check(string s1, string s2){
        
        if(s1.find("0")!=string::npos) return false;
        if(s2.find("0")!=string::npos) return false;
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {

        vector<int>ans;
        for(int i=1;i<n;i++){
            string s1=to_string(i);
            string s2=to_string(n-i);
            if(check(s1,s2)){
                ans.push_back(i);
                ans.push_back(n-i);

                break;
            }

        }
        return ans;
    }
};