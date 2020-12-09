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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left=maxDepth(root->left)+1;
        int right=maxDepth(root->right)+1;
        return max(left,right);
    }
};

int main(){
    TreeNode root,n1,n2,n3,n4,n5;
    root.left=&n1;
    root.right=&n2;
    n1.left=&n3;
    n1.right=&n4;
    n3.left=&n5;
    Solution s;
    cout<<s.maxDepth(&root);
    
}