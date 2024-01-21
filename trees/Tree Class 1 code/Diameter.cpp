
//   Definition for a binary tree node.
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// i have doubt in this problem there is a minute mistake i am
// having in my logic building which i have to figure out first
// and that should be purely based on my understandig or else
// it will be only rattafication which i cant and is also not
// possible for me

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }

    // doubt in diameter of binary tree
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + 1 + maxDepth(root->right);
        int ans = max(op1, max(op2, op3));
        return ans;
    }
};