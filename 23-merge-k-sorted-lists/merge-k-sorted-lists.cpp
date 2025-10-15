class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        if(l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
        
        return NULL;
    }
    
    ListNode* solve(int start, int end, vector<ListNode*>& lists) {
        if(start == end)
            return lists[start];
        
        if(start > end)
            return NULL;
        
        int mid = start + (end-start)/2;
        
        ListNode* l1 = solve(start, mid, lists);
        ListNode* l2 = solve(mid+1, end, lists);
        
        return merge(l1, l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        
        if(n == 0)
            return NULL;
        
        return solve(0, n-1, lists);
        
    }
};