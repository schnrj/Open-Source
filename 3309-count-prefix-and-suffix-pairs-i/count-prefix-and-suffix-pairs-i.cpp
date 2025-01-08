class Solution {
public:
    bool check(string s1,string s2){
        int n=s1.size();
        string pre=s2.substr(0,n);
        string sachu=s2;
        string sach=s1;
        reverse(sach.begin(),sach.end());
        reverse(sachu.begin(),sachu.end());
        string suff=sachu.substr(0,n);
        if(pre==s1&&suff==sach) return true;
        else return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(check(words[i],words[j])) count++;

            }
        }
        return count;
    }
};