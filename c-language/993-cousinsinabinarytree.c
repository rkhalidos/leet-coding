/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Runtime: 0ms
Memory: 5.7MB
Top 100% of C submissions
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *findParent(struct TreeNode* root, int num);
int findDepth(struct TreeNode *root, int num);

bool isCousins(struct TreeNode* root, int x, int y){
    
    // Initialising required variables
    struct TreeNode *parentx =  NULL, *parenty = NULL;
    int depthx = 0, depthy = 0;
    
    // Find the element and depth for the first element
    parentx = findParent(root, x);
    depthx = findDepth(root, x);
    
    // Find the element and depth for second element
    parenty = findParent(root, y);
    depthy = findDepth(root, y);
    
    // Checking conditions
    if (parentx != NULL && parenty != NULL)
    {
        if (parentx == parenty) return false;
        else
        {
            if (depthy == depthx) return true;
            else return false;
        }
    }
    return false;
}

// Finding the parent 
struct TreeNode *findParent(struct TreeNode* root, int num)
{
    struct TreeNode *traversal = root;
    if(traversal->left != NULL)
    {   
        // base condition
        if (traversal->left->val == num)
        {
            return traversal;
        }
        else
        {   // recursive call to return NULL if not found or pointer if found
            struct TreeNode *result = NULL;
            result = findParent(traversal->left, num);
            if (result != NULL) 
                return result;
        }
    }
    if(traversal->right != NULL)
    {   
        // base condition
        if (traversal->right->val == num)
        {
            return traversal;
        }
        else
        {   
            // recursive call to return NULL if not found or pointer if found
            struct TreeNode *result = NULL;
            result = findParent(traversal->right, num);
            if (result != NULL) 
                return result;
        }
    }
    return NULL;
}

// Finding depth of the binary tree
int findDepth(struct TreeNode *root, int num)
{
    struct TreeNode* traversal = root;
    
    // to only start count when node is found; returns -1 if element not found
    if (traversal == NULL)
        return -1;
    // base condition
    if (traversal->val == num)
        return 0;
    else
    {
        int lDepth = findDepth(traversal->left, num);
        int rDepth = findDepth(traversal->right, num);
        // if either left or right branch has the number, only that is to be counted
        if (lDepth >= 0) return lDepth + 1;
        else if (rDepth >= 0) return rDepth + 1;
        // if not found, -1 is returned
        else return lDepth + rDepth + 1;
    }
}
