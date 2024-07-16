#include <iostream>
using namespace std;

// Algorithm used here-
// 1. reached the node which you want to delete it 
// 2. connect points (font and back)
// 3. free the memory (delete node)

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};

// case1 - If head to be delete
// case2 - according to position we will delete the node 
   
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        
        if(x == 1){
            Node * temp = head;
            temp = temp->next;
            return temp;
        }
        
        int count = 1;
        Node * temp = head;
        // Linked List is gonna to nullptr or count is gonna to equal to given position x
        while(temp != nullptr and count != x){
            temp = temp->next;
            count ++;
        }
        
        /* connect with after the delete the node - simple way 
        Node * back = temp->prev;
        Node * front = temp->next;
        back->next = front;
        front->prev = back;
        */
        
        temp->prev->next=temp->next;
        
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        
        delete temp;
        return head;
    }
};