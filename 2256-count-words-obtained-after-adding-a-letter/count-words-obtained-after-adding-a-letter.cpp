class Solution {
public:
struct Trie {
    Trie* ch[26] = {};
    bool end = false;

    void insert(const string& s, int p = 0) {
        if (p == s.size()) {
            end = true;
            return;
        }
        int idx = s[p] - 'a';
        if (!ch[idx]) ch[idx] = new Trie();
        ch[idx]->insert(s, p + 1);
    }

    bool find(const string& s, int p = 0, bool skipped = false) {
        if (p == s.size()) return skipped && end;

        int idx = s[p] - 'a';
        bool match = ch[idx] && ch[idx]->find(s, p + 1, skipped);
        bool skip = false;
        if (!skipped) {
            skip = find(s, p + 1, true);
        }
        return match || skip;
    }
};
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        Trie trie;
    for (auto& word : startWords) {
        sort(word.begin(), word.end());
        trie.insert(word);
    }

    int count = 0;
    for (auto& word : targetWords) {
        sort(word.begin(), word.end());
        if (trie.find(word)) {
            count++;
        }
    }
    return count;
    }
};