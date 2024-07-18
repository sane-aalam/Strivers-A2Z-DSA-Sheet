class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K) 
    { 
    
       // Your code here
       for(int currentIndex = 0; currentIndex < N; currentIndex++){
           if(arr[currentIndex] == K){
               return 1;
           }
       }
       
       // return -1, if array does'nt contain element
       return -1;
    }
};