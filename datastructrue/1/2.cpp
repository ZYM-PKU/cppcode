#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode *res;
        res = new TreeNode(preorder[preStart]);
        int flag;
        for (int i = inStart; i <= inEnd; i++) {
            if (preorder[preStart] == inorder[i]) {
                flag = i;
                break;
            }
        }
        res->left = buildTree(preorder, inorder, preStart + 1, preStart + flag - inStart, inStart, flag - 1);
        res->right = buildTree(preorder, inorder, preStart + flag - inStart + 1, preEnd, flag + 1, inEnd);
        return res;
    }
};

