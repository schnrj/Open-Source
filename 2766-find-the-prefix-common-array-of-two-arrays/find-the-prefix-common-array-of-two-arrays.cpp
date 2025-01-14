class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>v(A.size()+1,0);
        vector<int>sachu;
        for(int i=0;i<A.size();i++){
            v[A[i]]++;
            v[B[i]]++;
            int ans=0;
            for(int i=0;i<v.size();i++){
                if(v[i]>1){
                    ans++;
                }
            }
            sachu.push_back(ans);
        }
        return sachu;
    }
};