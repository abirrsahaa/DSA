/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {

        // base case
        if (root == NULL)
            return NULL;

        // i have fucking 4 cases
        // leaf node
        // if(!root->left && !root->right)return root;
        // // both not null
        // TreeNode *l=root->left;
        // TreeNode *r=root->right;
        // root->left=r;
        // root->right=l;

        // root->left=invertTree(root->left);
        // root->right=invertTree(root->right);

        // this above implementation is also correct
        // but what i have realised is that i can swap even the nodes of a tree
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);

        // so this solution gave me oms compared to the previous solution of 2ms

        return root;
    }
};