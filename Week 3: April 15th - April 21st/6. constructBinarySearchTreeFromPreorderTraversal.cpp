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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        if(pre.size() == 0)
            return NULL;
        
        TreeNode* root = new TreeNode(pre[0]);
        
        int i = 1;
        vector<int> preL;
        vector<int> preR;
        
        while(i < pre.size() && pre[i] < pre[0]){
            preL.push_back(pre[i]);
            i++;
        }
        while(i < pre.size() && pre[i] > pre[0]){
            preR.push_back(pre[i]);
            i++;
        }
        
        TreeNode* left = bstFromPreorder(preL);
        TreeNode* right = bstFromPreorder(preR);
       
        root->left = left;
        root->right = right;
        
        return root;
    }
};
