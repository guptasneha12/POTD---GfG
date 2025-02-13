class Solution {
    void inorder(Node* root,vector<int> &vec){
        if(root==NULL) return;
        inorder(root->left,vec);
        vec.push_back(root->data);
        inorder(root->right,vec);
    }
  public:
    bool findTarget(Node *root, int target) {
        // your code here.
        // USE inorder then use two pointer approach
        vector<int> vec;
        inorder(root,vec);
        int left=0,right=vec.size()-1;
        while(left<right){
            int sum=vec[left]+vec[right];
            if(sum==target) return true;
            else if(sum<target) left++;
            else right--;
        }
        return false;
        
    }
};