/*
  Invert a binary tree.
  
  Runtime: 0ms
  Memory: 5.6MB
  Top 100% of all C submissions
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    struct TreeNode *traversal = root;
    if (traversal == NULL) 
    {
        return NULL;
    }
    else
    {
        struct TreeNode *temp = traversal->left;
        traversal->left = traversal->right;
        traversal->right = temp;
        invertTree(traversal->left);
        invertTree(traversal->right);
    }
    return root;
}
