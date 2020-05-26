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
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int len = 0;
        while(p != nullptr)
        {
            ++len;
            p = p->next;
        }

        for(int i = 1; i < len ; i *= 2)
        {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            while(cur!=nullptr)
            {
                auto left = cur;
                auto right = cut(left,i);
                cur =  cut(right,i);

                tail->next = merge(left,right);
                while(tail->next)
                    tail = tail->next;
            }
        }
        return dummyHead.next;
    }

    ListNode *cut(ListNode *head, int n)
    {
        auto p = head;
        while(--n && p)
        {
            p = p->next;
        }
        if(!p) return nullptr;
        auto nextptr = p->next;
        p->next = nullptr;
        return nextptr;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;       
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};