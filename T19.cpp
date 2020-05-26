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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        ListNode *fast,*slow;
        fast = slow = tmp;
        while(len<=n)
        {
            len++;
            fast = fast->next;
        }
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return tmp->next;
        
        /*int len = 0;
        ListNode *first = head;
        while(first!=nullptr)
        {
            len++;
            first = first->next;
        }
        len -= n;
        first = head;
        if(len == 0)
            return head->next;
        while(--len>0)
            first = first->next;
        first->next = first->next->next;
        return head;*/
    }
};