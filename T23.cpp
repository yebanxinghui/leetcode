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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 :l2;//处理l1或者l2有剩余的情况
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())  return nullptr;
        int len = lists.size();
        int interval=1;
        while (len > interval)
	    {
		    for (int i = 0; i < len - interval; i += 2*interval)
		    {
			    lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
		    }
		    interval*=2;
	    }
        return lists[0];
    }
};