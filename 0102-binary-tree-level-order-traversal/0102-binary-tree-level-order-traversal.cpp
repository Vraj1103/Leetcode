/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<vector<int>> ans;

   void Levelorder(TreeNode* root,int level){
    if(root==NULL)return;
    if(level>=ans.size())ans.push_back({});

    ans[level].push_back(root->val);
    Levelorder(root->left,level+1);
    Levelorder(root->right,level+1);
   }

    vector<vector<int>> levelOrder(TreeNode* root) {
        Levelorder(root,0);
        return ans;
    }
};