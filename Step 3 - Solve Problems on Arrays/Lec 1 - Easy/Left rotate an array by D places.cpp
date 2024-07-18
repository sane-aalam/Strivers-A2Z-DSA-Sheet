
#include <bits/stdc++.h>
using namespace std;

// Two pointer algorithm - To reverse array elements

void solve(vector<int>& arr, int start, int end){


    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    int n = arr.size();
    
    solve(arr,0,k-1);
    solve(arr,k,n-1);
    solve(arr,0,n-1);

    return arr;
}
