//Source : https://leetcode.com/problems/reorder-list/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Medium
///////////////////////////////////////////////////////////////////
// You are given the head of a singly linked-list. The list can be represented as:
// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
///////////////////////////////////////////////////////////////////
// Solution: 
//Find the middle node, split into two, reverse the second half, merge two halves
// Solution complexity:
// Time : O(n)
// Space = O(1)
///////////////////////////////////////////////////////////////////
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
    void reorderList(ListNode* head) 
    {
       if(head->next == NULL)
           return;
        //Find middle node
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //Splitting into two halves;
        ListNode* second = slow->next;
        slow->next = NULL;
        // Reversing second half
        ListNode* temp;
        ListNode* prev = NULL;
        while(second != NULL)
        {
            temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        // Merging forst nad second halves
        ListNode* first = head;
        second = prev;
        ListNode* temp1;
        ListNode* temp2;
        while(second != NULL) // second half is usually the shortest
        {
            temp1 = first->next;
            temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
            
        }
    } 
};