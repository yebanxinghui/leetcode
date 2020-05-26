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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num=0;
        ListNode *p1=l1,*p2=l2;
        ListNode *l3 = new ListNode(l1->val+l2->val);
        if(l3->val>=10)
        {
            num = 1;
            l3->val-=10;
        }
        else num=0;
        p1 = p1->next;
        p2 = p2->next;
        ListNode *p3=l3,*p4=p3->next;
        while(p1!=nullptr && p2!=nullptr)
        {
            p4 = new ListNode(p1->val+p2->val+num);
            if(p4->val>=10)
            {
                num = 1;
                p4->val-=10;
            }
            else num=0;
            p3->next = p4;
            p1 = p1->next;
            p2 = p2->next;
            p3 = p4;
            p4 = p4->next;
        }
        while(p1!=nullptr)
        {
            p4 = new ListNode(p1->val+num);
            if(p4->val >= 10)
            {
                num = 1;
                p4->val -= 10;
            }
            else num=0;
            p3->next = p4;
            p1 = p1->next;
            p3 = p4;
            p4 = p4->next;
        }
        while(p2!=nullptr)
        {
            p4 = new ListNode(p2->val+num);
            if(p4->val >= 10)
            {
                num = 1;
                p4->val -= 10;
            }
            else num=0;
            p3->next = p4;
            p2 = p2->next;
            p3 = p4;
            p4 = p4->next;
        }
        if(num)
        {
            p4 = new ListNode(num);
            p3->next = p4;
            p3 = p4;
        }
        p3->next = nullptr;
        return l3;
    }
};