class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x) {

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
                result = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return result;
    }
};