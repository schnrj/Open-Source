class Solution {
public:
    bool check(string s, string t) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i]) {
                count++;
                if(count > 1) return false;
            }
        }
        return count == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);        
        vector<int> parent(n, -1);    

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(words[i].size() == words[j].size() &&
                   check(words[i], words[j]) &&
                   groups[i] != groups[j]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

    
        int maxi = 0;
        for(int i = 1; i < n; i++) {
            if(dp[i] > dp[maxi]) {
                maxi = i;
            }
        }

        
        vector<string> ans;
        for(int i = maxi; i != -1; i = parent[i]) {
            ans.push_back(words[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
