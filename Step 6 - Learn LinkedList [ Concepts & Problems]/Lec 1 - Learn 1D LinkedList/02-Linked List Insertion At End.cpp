#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// Algorithm to solve this basic question-
// 1. traverse the given linked list
// 2. create the new node using (value of x)
// 3. you can easly insert the new node into the given list 
//   temp->next = newNode
// 4. make sure given linked list is not null
// 5. given linked list is nullptr Then simple create the node return linked list only one node 
  
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        
        Node * newNode = new Node(x);
        if(head == nullptr){
            return newNode;
        }
        
        Node * temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
        return head;
    }
};