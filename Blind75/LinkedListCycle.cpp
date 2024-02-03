// Hint
// Used map
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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> m;
        while(head)
        {
            if(m[head] == false)
            {
                m[head] = true;
                head = head->next;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};