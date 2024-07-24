class Solution {
  public:
    // Function to find Ceil of x
    // n: size of vector
    // x: element whose floor is to find
    int findCeil(vector<long long> v, long long n, long long x) {

        // Your code here
        int start = 0;
        int end = n - 1;
        int target = x;
        int mid = start + (end - start)/2;
        
        int result = -1;

        while(start <= end){
            if(v[mid] == target){
                return mid;
            }else if(v[mid] < target){
                start = mid + 1;
            }else{
                 result = mid;
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return result;
    }
};