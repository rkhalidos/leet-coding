/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Rumtime: 0 ms
Memory: 5.5 MB
Top 100% of all C submissions
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if (!head || !head->next) return head;
    struct ListNode *swapNode = swapPairs(head->next->next);
    struct ListNode *newHead = head->next;
    newHead->next = head;
    head->next = swapNode;
    return newHead;
}
