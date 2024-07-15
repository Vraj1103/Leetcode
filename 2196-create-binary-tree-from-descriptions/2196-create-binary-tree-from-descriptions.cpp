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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_set<int>children,parents;
        unordered_map<int,vector<pair<int,int>>>ptoc;

        for(auto d:des){
            int parent = d[0];
            int child = d[1];
            bool isleft = d[2];

            parents.insert(parent);
            parents.insert(child);
            children.insert(child);

            ptoc[parent].emplace_back(child,isleft);
        }

        for(auto it=parents.begin();it!=parents.end();){
            if(children.find(*it)!=children.end()){
                it = parents.erase(it);
            }
            else  it++;
        }

        TreeNode* root= new TreeNode(*parents.begin());

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            for(auto ptc : ptoc[temp->val]){
                int childValue = ptc.first;
                int isLeft = ptc.second;
                TreeNode* child = new TreeNode(childValue);
                q.push(child);
                if(isLeft)temp->left=child;
                else temp->right = child;
            }

        }
    return root;
    }
};