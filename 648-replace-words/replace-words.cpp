class Solution {
public:
    struct Trie{
        map<char,Trie*> next;
        bool isend = false;
    };
    
    Trie* root;

    
    Trie* getNode() {
        return new Trie();
    }

    void insert(string word) {
        Trie* node = root; 
        for (char ch : word) {
            if (!node->next.count(ch)) {
                node->next[ch] = getNode(); 
            }
            node = node->next[ch];  
        }
        node->isend = true;
    }

    string search(string word) {
        Trie* node = root; 
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if (!node->next.count(ch)) {
                return word;  
            }
            node = node->next[ch];  
            if (node->isend) {
                return word.substr(0, i + 1);  
            }
        }
        return word; 
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string word;
        string result;

        root = getNode();  


        for (string word : dictionary) {
            insert(word);
        }

    
        while (ss >> word) {  
            result += search(word) + " "; 
        }

        result.pop_back();  
        return result;
    }
};
