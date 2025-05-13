/*
Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

Runtime: 20ms
Memory: 14.9 MB
Top 95.22% of all C submissions
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    if (root == NULL || root->val == val) return root;
    if (root->val < val) return searchBST(root->right, val);
    return searchBST(root->left, val);
}
