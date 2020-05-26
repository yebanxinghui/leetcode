/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dum = new ListNode(0);
        dum->next = head;

        ListNode *fast,*slow,*tmp,*start;
        fast = slow = start = dum;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            tmp = fast->next;
            start->next = fast;
            fast->next = slow;
            slow->next = tmp;
            start = fast = slow;
        }  
        return dum->next;
    }
};