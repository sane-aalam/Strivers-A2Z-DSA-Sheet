#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
   int FirstPosition(int arr[], int n, int k) {
        // code here'
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start)/2;
        
        int result1 = -1;
        while(start <= end){
            if(arr[mid] == k){
                result1 = mid;
                end = mid -1;
            }else if(arr[mid] < k ){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return result1;
    }
    int LastPosition(int arr[], int n, int k) {
        // code here'
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start)/2;
        
        int result2 = -1;
        while(start <= end){
            if(arr[mid] == k){
               result2 = mid;
               start = mid + 1;
            }else if(arr[mid] < k ){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return result2;
    }
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int result1 = FirstPosition(arr,n,x);
	    int result2 = LastPosition(arr,n,x);
	    if(result1 == -1 and result2 == -1) return 0;
	    int last = result2;
	    int first = result1;
	    int total = last - first + 1;
	    return total;
	}
};