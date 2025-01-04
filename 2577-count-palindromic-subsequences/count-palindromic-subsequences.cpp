const int mod = 1e9+7;
const int N = 1e4+1;

int fwd_dp[2][100][N];
int bck_dp[2][100][N];

class Solution {
    string s;
    vector<string> subsequences;
    
    int ForwardSubsequences (int s_ind, int sub_ind, int sub_str) {
        int sub_length = subsequences[sub_str].length();
        int s_length = s.length();
        
        if (sub_ind == sub_length) return 1;
        if (s_ind == s_length) return 0;
        
        int &ans = fwd_dp[sub_ind][sub_str][s_ind];
        if (ans != -1) return ans;
        
        ans = 0;
     
        ans = (ans + ForwardSubsequences (s_ind+1, sub_ind, sub_str)) % mod;
  
        if (subsequences[sub_str][sub_ind] == s[s_ind]) 
            ans = (ans + ForwardSubsequences(s_ind+1, sub_ind+1, sub_str)) % mod;
        
        return ans;
    }
    
    int BackwardSubsequences (int s_ind, int sub_ind, int sub_str) {    
        int sub_length = subsequences[sub_str].length();
        int s_length = s.length();
        
        if (sub_ind == sub_length) return 1;
        if (s_ind == -1) return 0;
        
        int &ans = bck_dp[sub_ind][sub_str][s_ind];
        if (ans != -1) return ans;
        
        ans = 0;
       
        ans = (ans + BackwardSubsequences (s_ind-1, sub_ind, sub_str)) % mod;
      
        if (subsequences[sub_str][sub_ind] == s[s_ind]) 
            ans = (ans + BackwardSubsequences(s_ind-1, sub_ind+1, sub_str)) % mod;
        
        return ans;
    }
    
    void Initialise() {
        memset(fwd_dp, -1, sizeof(fwd_dp));
        memset(bck_dp, -1, sizeof(bck_dp));
                
        for (int j = 0; j < 10; j ++) {
            for (int k = 0; k < 10; k ++) {
                string seq = "";
                seq += (char)(j + '0');
                seq += (char)(k + '0');
                subsequences.push_back(seq);
            }
        }
    }
    
public:
    int countPalindromes(string str) {
        Initialise();
        s = str;
        
        int n = s.length();
        int ans = 0;
        
        for (int mid = 2; mid < n-2; mid ++) {
            for (int i = 0; i < subsequences.size(); i ++) {
                long after = ForwardSubsequences (mid+1, 0, i);
                long before = BackwardSubsequences (mid-1, 0, i);
                
                ans = (ans + (before * after) % mod) % mod;
            }
        }
        return ans;
    }
};