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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odddummy = new ListNode();
        ListNode *evendummy = new ListNode();
        ListNode *p = head;
        ListNode *odd = odddummy;
        ListNode *even = evendummy;
        bool flag = true;
        while(p)
        {
            if(flag)
            {
                flag = false;
                odd->next = p;
                odd = odd->next;
            }
            else
            {
                flag = true;
                even->next = p;
                even = even->next;
            }
            p = p->next;
        }
        odd->next = evendummy->next;
        even->next = nullptr;
        return odddummy->next;
    }
};