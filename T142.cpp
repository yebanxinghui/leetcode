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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        do{
            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }while (slow != fast);
        //找到slow=fast点为环中一个点
        slow = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
        /*
        unordered_map<ListNode*,int> m;
        int pos = 0;
        fast = head;
        while(fast!=slow){
            m[fast] = pos++;
            fast = fast->next;
        }
        m[slow] = pos;
        slow = slow->next;
        while(m.find(slow)==m.end())
        {
            slow = slow->next;
        }
        return slow;*/
    }
};