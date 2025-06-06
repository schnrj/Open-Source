class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<char> sachu(n); 

        sachu[n-1] = s[n-1];
        for(int i = n-2; i >= 0; i--) {
            sachu[i] = min(s[i], sachu[i+1]);
        }


        string t = "";
        string paper = "";

        int i = 0; 
        while(i < n) {
            t.push_back(s[i]);

            char mini = (i+1 < n) ?sachu[i+1] : s[i];

            while(!t.empty() && t.back() <= mini) {
                paper += t.back();
                t.pop_back();
            }

            i++;
        }

        
        while(!t.empty()) {
            paper += t.back();
            t.pop_back();
        }

        return paper;
    }
};
