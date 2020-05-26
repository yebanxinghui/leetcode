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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *fast = head,*slow = head,*pre = nullptr;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        while(slow)
        {
            ListNode *p =slow->next;
            slow->next = pre;
            pre = slow;
            slow = p;
        }

        while(head && pre)
        {
            if(head->val != pre->val) return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};