class Solution {
public:
     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> res(n), cnt(51);
    for (int i = 0; i < n; ++i) {
        res[i] = (++cnt[A[i]] == 2 ? 1 : 0) + (++cnt[B[i]] == 2 ? 1 : 0);
        if( i > 0)  res[i] += res[i - 1];
    }
    return res;
}
};