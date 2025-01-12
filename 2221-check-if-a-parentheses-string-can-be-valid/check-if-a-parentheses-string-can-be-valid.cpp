class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) return false;

        int o = 0, c = 0, w = 0;

        // Forward pass
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') w++;
            else if (s[i] == '(') o++;
            else c++;

            if (o + w < c) return false; 
        }

        o = 0, c = 0, w = 0;

       
        for (int i = s.size() - 1; i >= 0; i--) { 
            if (locked[i] == '0') w++;
            else if (s[i] == ')') c++;
            else o++;

            if (c + w < o) return false; 
        }

        return true;
    }
};
