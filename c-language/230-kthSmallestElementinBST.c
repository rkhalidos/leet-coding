/*
  Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

  Note:
  You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
  
  Runtime: ms
  Memory: MB
  Top 75.25% of all C submissions
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void findkthSmallestNode(struct TreeNode* node, int k, int* count, int* result);
int kthSmallest(struct TreeNode* root, int k){
    int count = 0, result = -1;
    findkthSmallestNode(root, k, &count, &result);
    return result;
}

void findkthSmallestNode(struct TreeNode* node, int k, int* count, int* result)
{
    if (*count >= k) return;
    if (node->left) findkthSmallestNode(node->left, k, count, result);
    (*count)++;
    if (*count == k) {*result = node->val; return;}
    if (node->right) findkthSmallestNode(node->right, k, count, result);
}
