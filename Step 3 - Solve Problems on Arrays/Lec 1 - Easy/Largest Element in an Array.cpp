

class Solution  {
public:
    int largest(vector<int> &arr, int n)
    {
        
       int largestElement = arr[0];
       for(int currentIndex = 1; currentIndex < n; currentIndex++){
           if(arr[currentIndex] > largestElement){
               largestElement = arr[currentIndex];
           }
       }
       return largestElement;
    }
};
