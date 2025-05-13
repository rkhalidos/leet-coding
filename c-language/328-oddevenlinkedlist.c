/* 
  Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

  You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
  
  Runtime: 4ms
  Memory: 6.7MB
  Top 94.53% of C submissions
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *traversal = head->next->next, *lastOdd = head, *lastEven = head->next, *firstEven = lastEven;
    while (traversal != NULL)
    {
        lastOdd->next = traversal;
        lastOdd = traversal;
        if (traversal->next != NULL)
        {
            lastEven->next = traversal->next;
            lastEven = traversal->next;
        }
        else break;
        traversal = traversal->next->next;
    }
    lastOdd->next = firstEven;
    lastEven->next = NULL;
    return head;
}
