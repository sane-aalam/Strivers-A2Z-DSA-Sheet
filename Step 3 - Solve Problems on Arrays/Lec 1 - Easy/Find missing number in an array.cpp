// 268. Missing Number


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
       
        int larg = *max_element(nums.begin() , nums.end());
        
        for(int i = 0; i<larg; i++){
            mp[i]++;
            if(i < nums.size()){
                mp[nums[i]]++;
            }
            
        }
        
        int result;
        for(auto it : mp){
            if(it.second == 1){
                result = it.first;
                return result;
            }
        }
        return larg+1;
    }
};



// Optimization of the space complexity 
// TC - 0(N)
// SC - 0(1)
// implement a solution using only O(1) extra space complexity and 
// O(n) runtime complexity
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // easy to understand approach using math
        int n = nums.size(); 
        int totalNumber = (n*(n+1)/2);
        int totalSum = 0;
        for(int currentIndex = 0; currentIndex < n; currentIndex++){
                totalSum += nums[currentIndex];
        }

        return totalNumber - totalSum;
    }
};