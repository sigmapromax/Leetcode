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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* lastSorted = head;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            if (lastSorted->val <= curr->val)
                lastSorted = lastSorted->next;
            else {
                ListNode* pre = dummy;
                while (pre->next->val <= curr->val)
                    pre = pre->next;
                lastSorted->next = curr->next;
                curr->next = pre->next;
                pre->next = curr;
            }
            curr = lastSorted->next;
        }
        return dummy->next;
    }
};
