/*
  Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.  
  
  Runtime: 0 ms
  Memory: 6.1 MB
  Top 100% of all C submissions.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if (node->next != NULL)
    {
      node->val = node->next->val;
      node->next = node->next->next;
    }
}
