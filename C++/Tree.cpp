/* 
	level(l)					height(h)
	  0			   1				1
				/     \
	  1		   2       3			2
			  / \     / \
	  2		 4  NULL NULL NULL		3
			/ \
	  3	 NULL NULL					4
	 
	*In Binary tree where every node has 0 or 2 children, the number of leaf nodes is 
		always one more than nodes with two children. T = L + 1
	*The maximum number of nodes at level 'l' of a binary tree is 2^l
	*The Maximum number of nodes in a binary tree of height 'h' is 2^h – 1
	*In a Binary Tree with N nodes, minimum possible height or the minimum 
		number of levels is? Log2(N+1) 	
    */

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
	public:
		int data;
		Node *left;
		Node *right;
		
		// val is the key or the value that
		// has to be added to the data part
		Node(int val){
			data = val;
			// Left and right child for node
			// will be initialized to null
			left = NULL;
			right = NULL;
		}
};

// returns max of two integers
int max(int a, int b){
	return (a > b) ? a : b; 
}

/* Given a binary tree, print its nodes in preorder or Depth First Traversal*/
void preorder(Node *node){
	if(node==NULL)return;
	
	/* first print data of node */
	cout<<node->data<<" ";
	/* then recur on left subtree */
	preorder(node->left);
	/* now recur on right subtree */
	preorder(node->right);
}

/* Given a binary tree, print its nodes in inorder Depth First Traversal*/
void inorder(Node *node){
	if(node==NULL)return;
	
	/* first recur on left subtree */
	inorder(node->left);
	/* then print data of node */
	cout<<node->data<<" ";
	/* now recur on right subtree */
	inorder(node->right);
}

/* Given a binary tree, print its nodes in postorder Depth First Traversal*/
void postorder(Node *node){
	if(node==NULL)return;
	
	/* first recur on left subtree */
	postorder(node->left);
	/* then recur on right subtree */
	postorder(node->right);
	/* now print data of node */
	cout<<node->data<<" ";
	
}

// Iterative method to find height of Binary Tree or Breadth First Traversal
void levelorder(Node *root){
	
	// Base Case
	if(root==NULL)return;
	
	// Create an empty queue for level order traversal
	queue<Node *>q;
	
	// Enqueue Root and initialize height
	q.push(root);
	int height = 0;
	
	while(!q.empty()){
		// Print front of queue and remove it from queue
		Node *node = q.front();
		cout<<node->data<<" ";
		q.pop();
		// increase height by 1
		height= height + 1;
		
		/* Enqueue left child */
		if(node->left != NULL)
			q.push(node->left);
		/* Enqueue right child */
		if(node->right != NULL)
			q.push(node->right);
	}
}

// The function Compute the "height" of a tree. Height is
// the number f nodes along the longest path from the root
// node down to the farthest leaf node.
int height(Node * node){
	// base case tree is empty
	if(node==NULL)return 0;
	// If tree is not empty then height = 1 + max of left
    // height and right heights
	return 1 + max(height(node->left),height(node->right));
}

// Function to get diameter of a binary tree
int diameter(Node *root,int *height){
	
	
	// lh --> Height of left subtree
    // rh --> Height of right subtree
	int lh = 0,rh = 0;
	
	// ldiameter  --> diameter of left subtree
    // rdiameter  --> Diameter of right subtree
    int ldiameter = 0, rdiameter = 0;
	
	if(root==NULL){
		*height = 0;
		return 0; // diameter is also 0
	}
	
	// Get the heights of left and right subtrees in lh and
    // rh And store the returned values in ldiameter and
    // ldiameter
    ldiameter = diameter(root->left, &lh);
    rdiameter = diameter(root->right, &rh);
  
    // Height of current node is max of heights of left and
    // right subtrees plus 1
    *height = max(lh, rh) + 1;
  
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

/* Iterative function for inorder tree
   traversal */
void inOrder(Node *root){
	stack<Node *>s;
	Node *curr = root;
	
	while(curr != NULL || s.empty()==false){
		/* Reach the left most Node of the
           curr Node */
		while(curr != NULL){
			/* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
		}
		/* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
	}
}

int main(){
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	cout << "\nPreorder traversal of binary tree is \n";
    preorder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    inorder(root);
 
    cout << "\nPostorder traversal of binary tree is \n";
    postorder(root);
	
	cout << "\nLevel Order traversal of binary tree is \n";
    levelorder(root);
	
	int height = 0;
    // Function Call
    cout << "\nDiameter of the given binary tree is " << diameter(root, &height);
	
	cout << "\nInorder traversal of binary tree using iterative is \n";
    inOrder(root);
	return 0;
}