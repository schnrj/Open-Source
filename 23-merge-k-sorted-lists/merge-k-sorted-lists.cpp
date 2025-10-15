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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>ans;
        for(int i=0;i<lists.size();i++){
            ListNode*head=lists[i];
            while(head!=nullptr){
                ans.push_back(head->val);
                head=head->next;
            }
        }
         if(ans.size()==0) return nullptr;
         sort(ans.begin(),ans.end());
         

         ListNode dummy(0);
         ListNode*tail=&dummy;
         int n=ans.size();
         int i=0;
         while(i<n){
            tail->next=new ListNode(ans[i]);
            tail=tail->next; 
            i++;
         }
         return dummy.next;
        //  return head;
        // return result;
    }
};