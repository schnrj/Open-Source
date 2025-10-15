/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode*head1=list1;
        ListNode*head2=list2;
        if(head1->val<=head2->val){
            head1->next=mergeTwoLists(head1->next,head2);
            return head1;
        }
        else{
            head2->next=mergeTwoLists(head1,head2->next);
            return head2;
        }
        
        return NULL;
    }
};