// A simple CPP program to introduce
// a doubly linked list

#include<iostream>
using namespace std;

/* Node of a doubly linked list */
class Node{
	public:
		int data;
		Node *next; // Pointer to next node in DLL
		Node *prev; // Pointer to previous node in DLL
}; 

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void insertAtBeginning(Node **head,int data){
	// Allocate memory to a node
	// struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	Node *newnode = new Node();
	//put in the data
	newnode->data = data;
	//Make next of new node as head
	newnode->next = *head;
	newnode->prev = NULL;
	//move the head to point to the new node
	(*head)->prev = newnode;
	*head = newnode;
}

void insertAtEnd(Node **head,int data){
	// Allocate memory to a node
	Node *newnode = new Node();
	//put in the data
	newnode->data = data;
	newnode->next=NULL;
	if(*head==NULL){	
		newnode->prev=NULL;
		*head = newnode;
		return;
	}
	Node *temp = *head;
	while(temp->next!=NULL)
		temp=temp->next;
	
	temp->next=newnode;
	newnode->prev=temp;
}

// Insert a node after a node
void insertAfter(Node *pre,int data){
	if(pre==NULL){
		cout<<"Node can't be NULL";
		return;
	}
	Node *newnode = new Node();
	newnode->data = data;
	newnode->next = pre->next;
	if(pre->next->prev!=NULL)
		pre->next->prev = newnode;
	newnode->prev = pre;
	pre->next = newnode;
}

/* Given a node as next_node, insert a new node before the
 * given node */
 void insertBefore(Node **head,Node *nextnode,int data){
	//check if the given next_node is NULL
	if(nextnode==NULL){
		cout<<"the given nect node cannot be null\n";
		return;
	}
	//allocate new node
	Node *newnode = new Node();
	//put in the data
	newnode->data = data;
	//Make prev of new node as prev of nextnode
	newnode->prev = nextnode->prev;
	//Make the prev of nextnode as newnode
	nextnode->prev = newnode;
	//Make nextnode as next of newnode
	newnode->next = nextnode;
	//Change next of new_node's previous node
	//If the prev of new_node is NULL, it will be the new head node
	if(newnode->prev!=NULL)
		newnode->prev->next=newnode;
	else (*head) = newnode;
 }
 
// This function prints contents of linked list starting
// from the given node
void printList(Node* node)
{
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while(node != NULL) {
        cout<<node->data<<" ";
        last = node;
        node = node->next;
    }
 
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL) {
        cout<<last->data<<" ";
        last = last->prev;
    }
}

/* Function to delete a node in a Doubly Linked List.
head_ref --> pointer to head node pointer.
del --> pointer to node to be deleted. */
void deleteNode(Node** head, Node* del){
	/* base case */
    if (*head == NULL || del == NULL)
        return;
 
    /* If node to be deleted is head node */
    if (*head == del)
        *head = del->next;
 
    /* Change next only if node to be
    deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    /* Change prev only if node to be
    deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
	
	/* Finally, free the memory occupied by del*/
    delete del;
}

/* Function to reverse a Doubly Linked List */
void reverse(Node **head){
    Node *temp = NULL;
    Node *current = *head;
     
    /* swap next and prev for all nodes of
    doubly linked list */
    while (current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;            
        current = current->prev;
    }
     
    /* Before changing the head, check for the cases like empty
        list and list with only one node */
    if(temp != NULL )
        *head = temp->prev;
}
 
 /* Driver program to test above functions*/
int main(){
    /* Start with the empty list */
    Node* head = NULL;
    insertAtEnd(&head, 7);
 
    insertAtEnd(&head, 1);
 
    insertAtEnd(&head, 4);
 
    // Insert 8, before 1. So linked list becomes
    // 4->8->1->7->NULL
	printList(head);
    insertBefore(&head, head->next, 8);
	printList(head);
	insertAfter(head->next,2);
	printList(head);
	insertAtBeginning(&head,5);
	printList(head);
	deleteNode(&head,head->next);
    printf("Created DLL is: ");
    printList(head);
	reverse(&head);
	printList(head);
    return 0;
}