//============================================================================
// Name        : Postorder Traversal (Iterative).cpp
// Author      : SidPro
// Version     : 1.0
// Description :
/*
Given a binary tree. Find the postorder traversal of the tree without using recursion.
Postorder Traversal (Iterative)

1. Push root to first stack.

2. Loop while first stack is not empty

   2.1 Pop a node from first stack and push it to second stack

   2.2 Push left and right children of the popped node to first stack

3. Print contents of second stack
*/
//============================================================================

vector<int> postOrder(Node* root) {
    // code here
    vector<int> v;
    if (root == NULL)
        return v;

    // Create two stacks
    stack<Node *> s1, s2;

    // push root to first stack
    s1.push(root);
    Node* node;

    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        v.push_back(node->data);
    }
    return v;
}