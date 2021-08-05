/*
Path Sum II
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.
A leaf is a node with no children.
*/

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
    void getAllPaths(TreeNode *root,int targetSum,vector<int> temp,vector<vector<int>> &ans)
    {
        if(!root)
            return;
        if(!root->left and !root->right and targetSum == root->val)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        getAllPaths(root->left,targetSum-root->val,temp,ans);
        getAllPaths(root->right,targetSum-root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        getAllPaths(root,targetSum,{},ans);
        return ans;
    }
};