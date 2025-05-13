/*
  Reverse a singly linked list.
  
  Rumtime: 0 ms
  Memory: 5.9MB
  Top 100% of all C submissions
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    if (head != NULL)
    {
        struct ListNode *traversal = head, *reverseNode = NULL;
        while (traversal != NULL)
        {
            struct ListNode *currentNode = traversal;
            traversal = traversal->next;
            currentNode->next = reverseNode;
            reverseNode = currentNode;
            head = currentNode;
        }
    }
    return head;
}
