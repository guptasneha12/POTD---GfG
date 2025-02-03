class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
    if(node==NULL) return 0;
        if(node->left==NULL && node->right==NULL) return 0;
        int leftheight=height(node->left);
        int rightheight=height(node->right);
        int ans=max(leftheight,rightheight)+1;
        return ans;
    }
};
