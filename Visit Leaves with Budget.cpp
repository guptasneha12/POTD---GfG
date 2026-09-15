/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
  void solve(Node *root,vector<int> &leafheight,int level){
      if(!root) return;
      level++; // for root node;
      if(!root->left && !root->right){
          leafheight.push_back(level);
          return;
      }
      
     solve(root->left,leafheight,level);
     solve(root->right,leafheight,level);
  }
  
    int getCount(Node *root, int k) {
        // code here
        vector<int> leafheight;
        solve(root,leafheight,0);
        sort(leafheight.begin(),leafheight.end());
            int cnt=0;
            for(int h:leafheight){
                if(k<h){
                    break;
                }
                k-=h;
                cnt++;
            }
        
        return cnt;
    }
};