/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // Solution 1.
//     class pair2{
//       public:
//       int height=0;
//       int diameter=0;
//     };

//     pair2 height_diameter(TreeNode* root){
//       pair2 ans,leftans,rightans;
//       if(root==NULL)
//         return ans;
//       if(root->left!=NULL)
//         leftans=height_diameter(root->left);
//       if(root->right!=NULL)  
//         rightans=height_diameter(root->right);

//       ans.height=1+max(leftans.height,rightans.height);
//       int l=leftans.diameter;
//       int r=rightans.diameter;
//       int h=leftans.height+rightans.height;
//       ans.diameter=max(l,max(r,h));
//       return ans;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         pair2 ans;
//         ans=height_diameter(root);
//         return ans.diameter;
//     }
    
    
    // Solution 2.
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int lH = height(root->left);
        int rH = height(root->right);
        
        return (1 + max(lH, rH));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int lH = height(root->left);
        int rH = height(root->right);
        int h = lH + rH;
        
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);
        
        int diameter = max(h, max(leftDia, rightDia));
        
        return diameter;
    }

    
};
