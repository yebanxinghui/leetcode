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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = nullptr;
        ListNode *n = head;
        while(n!=nullptr)
        {
            ListNode *tmp =n->next;
            n->next = p;
            p = n;
            n = tmp;
        }
        return p;
    }
};