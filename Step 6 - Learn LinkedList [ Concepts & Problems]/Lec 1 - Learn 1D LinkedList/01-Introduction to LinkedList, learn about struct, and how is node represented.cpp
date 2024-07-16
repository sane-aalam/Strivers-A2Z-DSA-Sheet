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
    Node* constructLL(vector<int>& arr) {
    // code here    
    // originalHead store the head node address of the linked list 
    // we want to have original head of the linked list
    // we have to return original head of the linked list 
    // tip-1 (make sure don't lose head address)
    // tip-2 (do dry run more)
    // tip-3 (love linked list data structure.)
        Node * HeadNode = new Node(arr[0]);
        Node * originalHead = HeadNode;
        
        // 1 <= n <= 105 
        // it will be passed because size always greater than 1
        if(arr.size() == 0){
            return nullptr;
        }
        
        // suppose your array size only 1, Then directly 
        // you can return only node linked list Which you have alredy created
        // no need to run [for loop concept]
        if(arr.size() == 1){
            return HeadNode;
        }
        
        for(int i = 1; i<arr.size(); i++){
            Node * temp = new Node(arr[i]);
            HeadNode->next = temp;
            HeadNode = HeadNode->next;
        }
        
        HeadNode->next = nullptr;
        return originalHead;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        Node* ans = obj.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }
    return 0;
}