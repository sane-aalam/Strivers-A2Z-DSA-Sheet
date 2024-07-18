
// Using HASHMAP
// TC - 0(N)
// SC - 0(N)
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        unordered_map<int,int> mp;
        for(int i = 0; i<size; i++){
            mp[a[i]]++;
        }
        
        for(auto it : mp){
            if(it.second > size/2){
                return it.first;
            }
        }
        return -1;
    }
};

// implement a solution using only O(1) extra space complexity and O(n) runtime complexity
// Using 'MORE VOTING ALGORITHM'

class Solution {
public: 
    // inorder to reduce the space complexity of the code
    // we can use "MORE VOTING ALGORITHM"
    // 1. declare the firstCandidate,With count = 1
    // 2. if you got same vote,Then incease the count
    // 3. if you not got same vote,Then decease the count 
    // 4. repeat the process 
    int majorityElement(vector<int>& nums) {
      
      int majorityElementCandidate = 0;
      int count = 0;
      for(int index = 0; index < nums.size(); index++){
        // When count become zero,This is time to assign new Candidate with count = 1
        // apply the process 
          if(count == 0){
            count = 1;
            majorityElementCandidate = nums[index];
          }else if(majorityElementCandidate == nums[index]){
            count++;
          }else{
            count--;
          }
      }
       
      int majorityElementNumberTimes = 0;
      for(int index = 0; index < nums.size(); index++){
        if(majorityElementCandidate == nums[index]){
            majorityElementNumberTimes ++;
        }
      }

      if(majorityElementNumberTimes > nums.size()/2)
        return majorityElementCandidate;
      
      return -1;
    }
};