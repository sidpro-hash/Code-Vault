//============================================================================
// Name        : Preorder traversal (Iterative).cpp
// Author      : SidPro
// Version     : 1.0
// Description :
/*
Preorder traversal (Iterative)
Given a binary tree. Find the preorder traversal of the tree without using recursion.
*/
//============================================================================
vector<int> preOrder(Node* root){
    vector<int> v;
    if (root == NULL)
        return v;

    stack<Node*> st;

    // start from root node (set current node to root node)
    Node* curr = root;

    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) {
            v.push_back(curr->data);

            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }

        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
    return v;
}