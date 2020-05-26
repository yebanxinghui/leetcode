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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while(pa != pb)
        {
            pa = pa->next;
            pb = pb->next;
            if(pa == nullptr && pb == nullptr)
                return nullptr;
            if(pa == nullptr)
                pa = headB;
            if(pb == nullptr)
                pb = headA;
        }
        return pa;
    }
};