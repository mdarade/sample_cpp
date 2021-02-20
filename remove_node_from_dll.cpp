// C++ program to delete a node from
// Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

/* a node of the doubly linked list */
class Node 
{ 
	public:
	int data; 
	Node* next; 
	Node* prev; 
}; 


//case 1: node to be deleted is head node itself
//case 2: node to be deleted is the middle somewhere 
//case 3: node to be deleted is the last node of Node
void RemoveNode(Node** head, Node* node) {
		if (*head == nullptr || node == nullptr)
			return ;

		if (*head == node) {
			*head = node->next;
		}

		Node* p_neighbour = node->prev;
		Node* n_neighbour = node->next;  

		if (n_neighbour)
			n_neighbour->prev = p_neighbour;

		if (p_neighbour)
			p_neighbour->next = n_neighbour;
		
		free (node);
}

/* Function to delete a node in a Doubly Linked List. 
head_ref --> pointer to head node pointer. 
del --> pointer to node to be deleted. */
void deleteNode(Node** head_ref, Node* del) 
{ 
	/* base case */
	if (*head_ref == NULL || del == NULL) 
		return; 

	/* If node to be deleted is head node */
	if (*head_ref == del) 
		*head_ref = del->next; 

	/* Change next only if node to be 
	deleted is NOT the last node */
	if (del->next != NULL) 
		del->next->prev = del->prev; 

	/* Change prev only if node to be 
	deleted is NOT the first node */
	if (del->prev != NULL) 
		del->prev->next = del->next; 

	/* Finally, free the memory occupied by del*/
	free(del); 
	return; 
} 

/* UTILITY FUNCTIONS */
/* Function to insert a node at the
beginning of the Doubly Linked List */
void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data; 

	/* since we are adding at the beginning, 
	prev is always NULL */
	new_node->prev = NULL; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* change prev of head node to new node */
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print nodes in a given doubly linked list 
This function is same as printList() of singly linked list */
void printList(Node* node) 
{ 
	while (node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

/* Driver code*/
int main() 
{ 
	/* Start with the empty list */
	Node* head = NULL; 

	/* Let us create the doubly linked list 10<->8<->4<->2 */
	push(&head, 2); 
	push(&head, 4); 
	push(&head, 8); 
	push(&head, 10); 

	cout << "Original Linked list "; 
	printList(head); 

	/* delete nodes from the doubly linked list */
	RemoveNode(&head, head); /*delete first node*/
	RemoveNode(&head, head->next); /*delete middle node*/
	RemoveNode(&head, head->next); /*delete last node*/

	/* Modified linked list will be NULL<-8->NULL */
	cout << "\nModified Linked list "; 
	printList(head); 

	return 0;
} 

// This code is contributed by rathbhupendra


