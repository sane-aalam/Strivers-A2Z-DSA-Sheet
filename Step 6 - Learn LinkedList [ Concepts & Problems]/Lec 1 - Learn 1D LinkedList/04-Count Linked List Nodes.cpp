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

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        if(head == nullptr){
            return 0;
        }
        
        if(head->next == nullptr){
            return 1;
        }

    // step-1 traversal the linked list, incease the count
        int NumberOfNodes = 0;
        Node * temp = head;
        
        while(temp != nullptr){
            temp = temp->next;
            NumberOfNodes = NumberOfNodes + 1;
        }
        
        return NumberOfNodes;
    }
};