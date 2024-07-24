#include <bits/stdc++.h> 
/****************************************************************

Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

*****************************************************************/

Node *delAddLastNode(Node *head){

    if(head == nullptr){
        return nullptr;
    }

    if(head->next == nullptr){
        return head;
    }
    
	// Write your code here.
    Node * secondLast = nullptr;
    Node * last = head;

    while(last->next != nullptr){
        secondLast = last;
        last = last->next;
    }

    // making second last node to lastNode with help nullptr pointer
    secondLast->next = nullptr;
    
    // making last node to first Node
    last->next = head;

    // update the head node with lastNode
    head = last;
    return head;
}