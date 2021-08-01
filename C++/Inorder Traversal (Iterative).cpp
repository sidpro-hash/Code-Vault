//============================================================================
// Name        : Inorder Traversal (Iterative).cpp
// Author      : SidPro
// Version     : 1.0
// Description :
/*
Inorder Traversal (Iterative)
Given a binary tree. Find the inorder traversal of the tree without using recursion.
*/
//============================================================================

class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> v;
        if(root==NULL)return v;
        stack<Node *> s;
        Node *curr = root;
    
        while (curr != NULL || s.empty() == false)
        {
            /* Reach the left most Node of the
               curr Node */
            while (curr !=  NULL)
            {
                /* place pointer to a tree node on
                   the stack before traversing
                  the node's left subtree */
                s.push(curr);
                curr = curr->left;
            }
    
            /* Current must be NULL at this point */
            curr = s.top();
            s.pop();
    
            v.push_back(curr->data);
    
            /* we have visited the node and its
               left subtree.  Now, it's right
               subtree's turn */
            curr = curr->right;
    
        } /* end of while */
        return v;
    }
};