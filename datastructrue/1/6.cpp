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
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q) {
        if(! root|| p == root || q == root)return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left && right)return root;
        return left? left : right;
    }
};

int main(){
    TreeNode root(0),n1(1),n2(2),n3(3),n4(4),n5(5);
    root.left=&n1;
    root.right=&n2;
    n1.left=&n3;
    n1.right=&n4;
    n3.left=&n5;
    Solution s;
    cout<<s.lowestCommonAncestor(&root,&n5,&n4)->val;
    
}