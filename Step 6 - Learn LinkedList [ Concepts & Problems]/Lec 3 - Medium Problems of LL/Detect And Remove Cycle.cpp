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

bool detectAndRemoveCycle(Node* head)
{
    // Write your code here
	Node * slow  = head;
	Node * fast = head;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast){
		
		// slow again intillization with head 
		// run both of same speed by 1
			slow = head;
			while(slow != fast){
				slow = slow->next;
				fast = fast->next;
			}
			while(slow->next != fast){
				slow = slow->next;
			}

			slow->next = nullptr;
			return true;
		}
	}
	return false;
}








