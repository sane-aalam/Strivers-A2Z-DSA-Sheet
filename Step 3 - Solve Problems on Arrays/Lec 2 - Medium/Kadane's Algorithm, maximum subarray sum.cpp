class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        long long current_sum = 0;
        long long maximum_sum = INT_MIN;
        
        for(int i = 0; i< arr.size(); i++){
            
           current_sum += arr[i];
           if(current_sum > maximum_sum){
               maximum_sum = current_sum;
           }
           if(current_sum < 0){
              current_sum = 0;
           }
        }
        return maximum_sum;
    }
};
