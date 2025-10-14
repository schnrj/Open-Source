class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string last_sorted = ""; 

        for (const string &w : words) {
            string t = w;
            sort(t.begin(), t.end());
            if (ans.empty() || t != last_sorted) {
                ans.push_back(w);
                last_sorted = t;
            }
          
        }
        return ans;
    }
};
