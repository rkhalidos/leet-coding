/*
  Return the root node of a binary search tree that matches the given preorder traversal.

  (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

  It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.
  
  Runtime: 0ms
  Memory: 7.8MB
  Top 100% of all C submissions.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* newNode (int data);
struct TreeNode* constructTree(int* preorder, int* index, int value, int min, int max, int preorderSize);

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    int index = 0; 
    return constructTree(preorder, &index, preorder[0], INT_MIN, INT_MAX, preorderSize); 
}

struct TreeNode* newNode (int data) 
{ 
    struct TreeNode* temp = (struct TreeNode *) malloc( sizeof(struct TreeNode) ); 
    temp->val = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
struct TreeNode* constructTree(int* preorder, int* index, int value, int min, int max, int preorderSize) 
{ 
    if(*index >= preorderSize) 
        return NULL; 
   
    struct TreeNode* root = NULL; 
   
    if(value > min && value < max ) 
    { 
        root = newNode(value); 
        (*index)++; 
        
        if (*index < preorderSize) root->left = constructTree(preorder, index, preorder[*index], min, value, preorderSize); 
        if (*index < preorderSize) root->right = constructTree( preorder, index, preorder[*index], value, max, preorderSize); 
    } 
    return root; 
} 
