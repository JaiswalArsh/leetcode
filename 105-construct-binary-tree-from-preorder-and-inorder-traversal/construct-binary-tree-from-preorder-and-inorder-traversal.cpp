/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* tree(vector<int>& preorder, int ps, int pe, vector<int>& inorder,
                   int is, int ie, map<int, int> &mp) {
        if (ps > pe || ie > ie)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = mp[root->val];
        int numL = inRoot - is;
        root->left =
            tree(preorder, ps + 1, ps + numL, inorder, is, inRoot - 1, mp);
        root->right =
            tree(preorder, ps + numL + 1, pe, inorder, inRoot + 1, ie, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        TreeNode* node = tree(preorder, 0, preorder.size() - 1, inorder, 0,
                              inorder.size() - 1, mp);
        return node;
    }
};