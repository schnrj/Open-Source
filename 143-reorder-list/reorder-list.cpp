
class Solution {
public:
    ListNode* mergeAlternately(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while (l1 != nullptr && l2 != nullptr) {
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;

            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
        }

        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }


        return dummy.next;
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        head = mergeAlternately(head, prev);
    }
};