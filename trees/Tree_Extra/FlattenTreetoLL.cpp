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
    void flatten(TreeNode *&root)
    {
        // base case
        if (root == NULL)
            return;
        // preorder traversal
        // save the left and the right part using the same class
        TreeNode *l = root->left;
        TreeNode *r = root->right;

        root->left = NULL;
        if (l)
        {
            root->right = l;
            root = root->right;
            flatten(root);
        }
        if (r)
        {
            root->right = r;
            root = root->right;
            flatten(root);
        }
        return;
    }
};

// !NOTE: this solution i did it by myself and although it gave me 0ms t.c but the space complexity was high
// !NOTE: lakshay sir has a better solution using the intution used in morris traversal kindly refer that solution !