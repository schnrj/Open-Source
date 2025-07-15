class Solution {
public:
  
    bool isPalindrome(string& str, int start, int end) {
        while(start < end) {
            if(str[start++] != str[end--]) return false;
        }
        return true;
    }

    
    void solve(int start, string& s, vector<string>& path, vector<vector<string>>& res) {
        if(start == s.size()) {
            res.push_back(path);
            return;
        }

        for(int end = start; end < s.size(); ++end) {
            if(isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                solve(end + 1, s, path, res);
                path.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, s, path, ans);
        return ans;
    }
};
