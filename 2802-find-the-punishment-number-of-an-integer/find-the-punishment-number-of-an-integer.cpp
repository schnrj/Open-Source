class Solution {
public:
   bool check(int i, string s, int sum){
    if(sum == 0 && i == s.size()) return true;
    if(sum < 0 || i >= s.size()) return false;
    bool res = false;
    for(int j = i+1; j <= s.size(); ++j) res |= check(j, s, sum - stoi(s.substr(i,j - i)));
    return res;
}

int punishmentNumber(int n) {
    int ans = 0;
    for(int i = 1; i <= n; ++i) ans += (check(0, to_string(i*i), i))? i*i : 0;
    return ans;
}
};