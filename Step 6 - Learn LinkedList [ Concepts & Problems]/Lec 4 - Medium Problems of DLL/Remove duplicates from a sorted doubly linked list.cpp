/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

// 1. currentNode or nextNode if there are Equal or not 
// 2. Change pointer 

class Solution{
public:
    Node * removeDuplicates(struct Node *head){
        // Your code here
       Node * temp = head;
       while(temp != nullptr && temp->next != nullptr){
           Node * nextNode = temp->next;
           
           while(nextNode != nullptr && nextNode->data == temp->data){
               nextNode = nextNode->next;
           }
           temp->next = nextNode;
           if(nextNode != nullptr){
                nextNode->prev = temp;
           }
           temp = temp->next;
       }
       return head;
    }
};
