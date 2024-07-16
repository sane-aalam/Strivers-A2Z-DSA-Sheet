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
    bool searchKey(int n, struct Node* head, int key) {
        // Code here
        
        Node * temp = head;
        
        while(temp != nullptr){
            int currentElement = temp->data;
            if(currentElement == key){
                return true;
            }
            temp = temp->next;
        }
        
        // not present into the linked list
        return false;
    }
};