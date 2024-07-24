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

bool circularLL(Node* head)
{
    // Write your code here
	Node * slow_pointer = head;
	Node * fast_pointer = head;

	while(fast_pointer != nullptr && fast_pointer->next != nullptr){
		slow_pointer = slow_pointer->next;
		fast_pointer = fast_pointer->next;
		if(fast_pointer->next != nullptr){
			fast_pointer = fast_pointer->next;
		}

		if(fast_pointer == slow_pointer){
			return true;
		}
	}
	return false;
}
