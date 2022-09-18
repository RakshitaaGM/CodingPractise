//Source : https://leetcode.com/problems/reverse-linked-list/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Easy
///////////////////////////////////////////////////////////////////
// Given the head of a singly linked list, reverse the list, and return
// the reversed list.
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
///////////////////////////////////////////////////////////////////
// Solution
// Declare prec,curr,next. Make curr->next poitn to prev
// Solution complexity
// Time : O(n)
//Space : O(1)
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
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};