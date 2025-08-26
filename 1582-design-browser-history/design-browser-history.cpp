struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
     string url;

    Node( string& url) : url(url) {}
};

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }

    string back(int steps) {
        while (curr->prev && steps-- > 0) {
            curr = curr->prev;
        }
        return curr->url;
    }

    string forward(int steps) {
        while (curr->next && steps-- > 0) {
            curr = curr->next;
        }
        return curr->url;
    }

private:
    Node* curr = nullptr;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */