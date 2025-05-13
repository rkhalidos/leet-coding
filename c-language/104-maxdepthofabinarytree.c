/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Runtime: 8 ms
Memory: 7.5 MB
Beats 17.49% of all C submissions 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    int leftDepth = 1 + maxDepth(root->left);
    int rightDepth = 1 + maxDepth(root->right);
    return (rightDepth >= leftDepth)? rightDepth : leftDepth;
}
