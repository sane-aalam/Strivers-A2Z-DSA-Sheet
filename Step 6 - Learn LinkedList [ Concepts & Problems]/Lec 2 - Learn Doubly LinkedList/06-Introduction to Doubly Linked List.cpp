#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    { 
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        if(arr.size() == 0){
            return nullptr;
        }
        
        Node * head = new Node(arr[0]);
        Node * temp = head;
        
        for(int index = 1; index < arr.size(); index++){
            Node * newNode = new Node(arr[index]);
            
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
        return head;
    }
};


