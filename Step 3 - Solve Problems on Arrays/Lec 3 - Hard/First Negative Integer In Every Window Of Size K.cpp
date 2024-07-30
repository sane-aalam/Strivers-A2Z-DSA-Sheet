#include <bits/stdc++.h> 
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{

    //Write your code here
    int i = 0;
    int j = 0;
    queue<int> deList;
    vector<int> result;

    while(j < n){
        
        if(arr[j] < 0){
             deList.push(arr[j]);
        }
        
// Indentify window size of k
        if((j - i + 1) < k){
            j++;
        }
// When Hit the window (j-i+1) 
//    1. do calculation according to questions
//    2. slide window of size k
        else if(j - i + 1 == k){
            if(deList.empty()){
                result.push_back(0);
            }else{
                result.push_back(deList.front());
                if(!deList.empty() && arr[i] == deList.front()){
                    deList.pop();
                }
            }
            i++;
            j++;
        }
    }
    return result;
}

