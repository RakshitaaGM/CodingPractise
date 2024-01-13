//Hint:
// USe one fast and one slow pointer. Move till n in the fast pointer. It will one element in the forward
// If fast in the last element, slow will be one element behind the element that has to be removed
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }
        if(!fast) return head->next;
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
        
    }
};