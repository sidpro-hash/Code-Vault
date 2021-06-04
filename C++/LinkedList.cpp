// A simple CPP program to introduce
// a linked list

#include<iostream>
#include <unordered_set>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

// This function prints contents of linked list
// starting from the given node
void printList(Node *n){
	while(n!= NULL){
		cout<< n->data <<" ";
		n=n->next;
	}
	cout<<"\n";
}

// How to write C functions that modify head pointer of a Linked List?
// https://www.geeksforgeeks.org/how-to-write-functions-that-modify-the-head-pointer-of-a-linked-list/
void insertAtBeginning(Node **head,int data){
	// Allocate memory to a node
	// struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	Node *newnode = new Node();
	//put in the data
	newnode->data = data;
	//Make next of new node as head
	newnode->next = *head;
	//move the head to point to the new node
	*head = newnode;
}

void insertAtEnd(Node **head,int data){
	// Allocate memory to a node
	Node *newnode = new Node();
	//put in the data
	newnode->data = data;
	newnode->next=NULL;
	if(*head==NULL){
		*head = newnode;
		return;
	}
	Node *temp = new Node();
	temp = *head;
	while(temp->next!=NULL)
		temp=temp->next;
	
	temp->next=newnode;
}

// Insert a node after a node
void insertAfter(Node * pre,int data){
	if(pre==NULL){
		cout<<"Node can't be NULL";
		return;
	}
	Node *newnode = new Node();
	newnode->data = data;
	newnode->next = pre->next;
	pre->next = newnode;
}

/* Given a reference (pointer to pointer) to the head of a
   list and a key, deletes the first occurrence of key in
   linked list */
void deleteNode(Node **head,int key){
	Node *temp = *head,*pre;
	// If head node itself holds the key to be deleted
	if(temp!=NULL && temp->data==key){
		*head = temp->next;// Changed head
		delete temp;// free old head
		return;
	}
	// Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
	while(temp!=NULL && temp->data!=key){
		pre = temp;
		temp=temp->next;
	}
	// If key was not present in linked list
	if(temp==NULL) return;
	// Unlink the node from linked list
	pre->next=temp->next;
	delete temp;
}

// Given a reference (pointer to pointer) to
// the head of a list and a position, deletes
// the node at the given position
void deleteNodeAt(Node **head,int position){
	// If linked list is empty
	if(*head==NULL)return;
	
	Node *temp = *head;
	if(position==0){
		*head = temp->next;
		delete temp;
		return;
	}
	
	// Find previous node of the node to be deleted
	for(int i=0;i<position-1&&temp!=NULL;++i)
		temp=temp->next;
	
	// If position is more than number of nodes
	if(temp==NULL || temp->next==NULL)return;
	
	// Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
	Node *delet = temp->next;
	temp->next = delet->next;
	
	delete delet;
}

/* Counts no. of nodes in linked list */
int getCount(Node *head){
	int count = 0;
	Node *temp = head;
	while(temp!=NULL){
		++count;
		temp=temp->next;
	}
	return count;
}

/* Recursively count number of nodes in linked list */
int getCountR(Node *head){
	int count = 0;
	// Base Case
	if(head==NULL)return 0;
	// Count this node plus the rest of the list
	else return 1 + getCountR(head->next);
}

/* Function to swap nodes x and y in linked list by
changing links */
void swapNodes(Node** head_ref, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y)
        return;
 
    // Search for x (keep track of prevX and CurrX
    Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
 
    // Search for y (keep track of prevY and CurrY
    Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }
 
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;
 
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head_ref = currY;
 
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        *head_ref = currX;
 
    // Swap next pointers
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

/* Function to reverse the linked list */
void reverse(Node **head){
	// Initialize current, previous and
    // next pointers
	Node *current = *head;
	Node *pre=NULL,*next=NULL;
	while(current!=NULL){
		// Store next
		next=current->next;
		// Reverse current node's pointer
		current->next=pre;
		// Move pointers one position ahead
		pre=current;
		current=next;
	}
	*head = pre;
}

/*Given two sorted linked lists consisting of N and M nodes
respectively. The task is to merge both of the list
(in-place) and return head of the merged list.*/
void SortedMergeHelper(Node **newhead,int data,Node **temp){
	// newhead is NULL
	if(*newhead==NULL){
		// Allocate memory to a node
		Node *newnode = new Node();
		// put in data
		newnode->data = data;
		newnode->next = NULL;
		*newhead = newnode;
		*temp=*newhead;
	}
	else{
		// Allocate memory to a node
		Node *newnode = new Node();
		// put in data
		newnode->data = data;
		newnode->next = NULL;
		(*temp)->next = newnode;
		*temp = newnode;
	}
}

Node *SortedMerge(Node *head,Node *head1){
	
	Node *newhead = NULL;
	Node *temp = newhead;
	
	if(head==NULL && head1==NULL)return newhead;
	if(head==NULL)return head1;
	if(head1==NULL)return head;
	
	while(head!=NULL && head1!=NULL){
		// check LinkedList1.Node < LinkedList2.Node
		if(head->data < head1->data){
			// append LinkedList1.Node to new LinkedList
			SortedMergeHelper(&newhead,head->data,&temp);
			//LinkedList1: Move pointers one position ahead
			head=head->next;
		}
		// check LinkedList1.Node > LinkedList2.Node
		else if(head->data > head1->data){
			// append LinkedList2.Node to new LinkedList
			SortedMergeHelper(&newhead,head1->data,&temp);
			//LinkedList2: Move pointers one position ahead
			head1=head1->next;
		}
		else{
			SortedMergeHelper(&newhead,head->data,&temp);
			head=head->next;
			SortedMergeHelper(&newhead,head1->data,&temp);
			head1=head1->next;
		}
	}
	
	while(head!=NULL){
		SortedMergeHelper(&newhead,head->data,&temp);
		head=head->next;
	}
	while(head1!=NULL){
		SortedMergeHelper(&newhead,head1->data,&temp);
		head1=head1->next;
	}
	
	return newhead;
}

/* Function to remove loop.
 loop_node --> Pointer to
 one of the loop nodes
 head -->  Pointer to the
 start node of the linked list */
 void removeLoop(Node *loop_node,Node *head){
	 Node *ptr2 = loop_node,*ptr1 = head;
	 
	 /* Set a pointer to the beginning
      of the Linked List and
      move it one by one to find the
      first node which is
      part of the Linked List */
	 while(1){
		/* Now start a pointer from
        loop_node and check if
		it ever reaches ptr2 */
		while(ptr2->next!=loop_node && ptr2->next!=ptr1)
			ptr2=ptr2->next;
		
		/* If ptr2 reahced ptr1
        then there is a loop. So
        break the loop */
		if(ptr2->next==ptr1)break;
		
		/* If ptr2 did't reach ptr1
         then try the next node
         * after ptr1 */
        ptr1 = ptr1->next;
	 }
	/* After the end of loop ptr2
    is the last node of the
    loop. So make next of ptr2 as NULL */
	ptr2->next = NULL;
 }
 
 void OptimizedremoveLoop(Node **slow,Node *head){
	Node * fast_p = *slow;
	Node *slow_p = head;
	// this check is needed when slow
    // and fast both meet at the head of the LL
    // eg: 1->2->3->4->5 and then
    // 5->next = 1 i.e the head of the LL
	if(slow_p==fast_p){
		while(fast_p->next!=slow_p)
			fast_p=fast_p->next;
	}
	else{
		while(slow_p->next != fast_p->next){
			slow_p=slow_p->next;
			fast_p=fast_p->next;
		}
	}
	/* since fast->next is the looping point */
    fast_p->next = NULL; /* remove loop */
 }


// Returns true if there is a loop in linked list
// else returns false.
bool detectLoop(Node *head){
	unordered_set<Node *> s;
	while(head!=NULL){
		// If this node is already present
        // in hashmap it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
		//  find returns end iterator if key is not found,
		//  else it returns iterator to that key
		if(s.find(head) != s.end())return true;
		
		// If we are seeing the node for
        // the first time, insert it in hash
		s.insert(head);
		head=head->next;
	}
	return false;
}

// the fastest method ot detect loop
// Floyd’s Cycle-Finding Algorithm 
bool detectLoopFCF(Node *head){
	//Traverse linked list using two pointers.
	Node *slow_p = head, *fast_p = head;
    //Move one pointer(slow_p) by one and another pointer(fast_p) by two.
    //If these pointers meet at the same node then there is a loop. 
	//If pointers do not meet then linked list doesn’t have a loop.
	while(slow_p && fast_p && fast_p->next){
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if(slow_p==fast_p){
			//removeLoop(slow_p, head);
			OptimizedremoveLoop(&slow_p,head);
			/* Return trure to indicate that loop is found */
			return true;
		}
	}
	return false;
}

/* Adds contents of two linked lists and
return the head node of resultant list */
Node *addTwoLists(Node *first,Node *second){

	// res is head node of the resultant list
	Node *res = NULL,*pre = NULL;
	int carry = 0,sum;
	//Traverse the two linked lists from start to end
	//Add the two digits each from respective linked lists.
	//If one of the lists has reached the end then take 0 as its digit.
	//Continue it until both the end of the lists.
	//If the sum of two digits is greater than 9 then set carry as 1 and the current digit as sum % 10
	
	while(first !=NULL || second != NULL){
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
		// update carry for next calulation
		carry = (sum>=10)?1:0;
		// update sum if it is greater than 10
		sum%=10;
		// Create a new node with sum as data
		Node *temp = new Node();
		temp->data = sum;
		temp->next==NULL;
		if(res==NULL){
			res=temp;
			pre = res;
		}
		else{
			pre->next=temp;
			pre=pre->next;
		}
		// Move first and second
        // pointers to next nodes
		if(first)first=first->next;
		if(second)second=second->next;
	}
	if(carry>0){
		Node *temp = new Node();
		temp->next=NULL;
		temp->data = 1;
		pre->next = temp;
	}
	return res;
}

// This function rotates a linked list
// counter-clockwise and updates the
// head. The function assumes that k is
// smaller than size of linked list.
// It doesn't modify the list if
// k is greater than or equal to size
void rotate(Node **head,int k){
	if(k==0)return;
	
	Node *current = *head;
	// current will either point to
    // kth or NULL after this loop.
	int count = 1;
	while(count<k && current != NULL){
		current = current->next;
		count++;
	}
	// If current is NULL, k is greater than
    // or equal to count of nodes in linked list.
    // Don't change the list in this case
    if (current == NULL)return;
	
	// current points to kth node.
    // Store it in a variable. kthNode
    Node* kthNode = current;
	
	// current will point to
    // last node after this loop
	while(current->next!=NULL)current=current->next;
	
	// Change next of last node to previous head
	current->next = *head;
	// Change head to (k+1)th node
	*head = kthNode->next;
	// change next of kth node to NULL
	kthNode->next=NULL;
}


int main(){
	Node *head = new Node();
	Node *third = new Node();
	Node *second = new Node();
	
	head->data=1; // assign data in first node
	head->next=second; // Link first node with second

	second->data=2;
	second->next=third;
	
	third->data=3;
	third->next=NULL;
	
	Node *head1 = new Node();
	Node *third1 = new Node();
	Node *second1 = new Node();
	
	head1->data=1; // assign data in first node
	head1->next=second1; // Link first node with second

	second1->data=2;
	second1->next=third1;
	
	third1->data=3;
	third1->next=NULL;
	
	Node *addedlist = addTwoLists(head,head1);
	printList(addedlist);
	
	Node *mergehead = SortedMerge(head,head1);
	printList(mergehead);
	
	cout<<"count: "<<getCount(head)<<"\n";
	insertAtBeginning(&head,0);
	insertAtEnd(&head,4);
	insertAfter(head->next,-1);
	printList(head);
	deleteNode(&head,12);
	printList(head);
	deleteNode(&head,0);
	printList(head);
	cout<<"count: "<<getCount(head)<<"\n";
	cout<<"count Recursively: "<<getCountR(head)<<"\n";
	swapNodes(&head, 1, 4);
	printList(head);
	reverse(&head);
	printList(head);
	
	/* Create a loop for testing */
	third->next=head;
	
	if(detectLoopFCF(head))cout<<"FCF Loop found, removing..."<<"\n";
	else cout<<"FCF No Loop"<<"\n";
	
	if(detectLoop(head))cout<<"Loop found"<<"\n";
	else cout<<"No Loop"<<"\n";
	
	rotate(&addedlist,2);
	printList(addedlist);
	return 0;
} 

   
						/* Floyd's Algorithm */
/*
                           
                                y--------|
                                |   5----6 _ M = Meeting point
								|  /     | |   
								| /      | |  M = x + y
                  1----2----3----4       | |  
				  |------x------| \      | |
								|  \     | |
								|   8----7 |
								-----------z	
								
					length of cycle L = y+z
					
		Proof:
		
		Turtle distance : x + y (slow pointer)
		Hare distance : 2*(x + y) (fast pointer) moves 2x faster than slow pointer
	
	we want to prove that: x mod L = z 
	
	from above figure, 
	
	2*(x + y) = M + k*L (k is count of loop that fast pointer will iterat)
	2*(x+y) = x+y + k*L
	x+y = k*L
	x = k*L - y
	now make mod L for both side,
	x mod L = (L+L+L+L+L+L..k times)-y mod L
	so value larger than L will be discraded because of mod L
	x mod L = (L - y) mod L
	x mod L = z mod L
	---------------
	| x mod L = z |
	---------------
	
	
	https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
*/