#include <bits/stdc++.h> 

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.

        // sort the arrray using STL
        sort(arr.begin(), arr.end());

		vector<vector<int>> result;

		set<vector<int>> st;

        int targetValue = K;
        for(int index = 0; index < n-2; index++){
            int start = index + 1;
            int end = n - 1;
            // Two pointer algorithm concept (Two-sum problem)
            while(start < end){
                int x = arr[index];
                int y = arr[start];
                int z = arr[end];
                int ThreeSum = x + y + z;

                if(ThreeSum == targetValue){
					vector<int> v;
					v.push_back(x);
					v.push_back(y);
					v.push_back(z);
					sort(v.begin(),v.end());
					st.insert(v);
					// result.push_back(v);
		// don't store directly result into 2D vector
		// store into the set - remove duplicate all 
	
					start++;
					end--;
		// Threesum Value is less than targetValue
		// incease the start pointer by 1 
                }else if(ThreeSum < targetValue){
					start++;
		// ThreeSum Value is greater Than TargetValue
		// decease the end pointer by 1 
				}else{
					end--;
				}
            }
        }

		for(auto nums : st){
			result.push_back(nums);
		}

	    return result;
}


// Leetcode solution
// When targetValue is Zero (0)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int targetValue = 0;
        
        set<vector<int>> st;
        vector<vector<int>> result;

        
        for(int i = 0; i<n; i++){
            int currentIndex = i;
            int start = i+1;
            int end = n - 1;
            
            while(start < end){
                int x = nums[currentIndex];
                int y = nums[start];
                int z = nums[end];
                
                // nums[i] + nums[j] + nums[k] == 0.
                int three_sum = x + y + z;
                if(three_sum == targetValue){
                    st.insert({x,y,z});
                    start++;
                    end--;
                }else if(three_sum < targetValue){
                    start++;
                }else{
                    end--;
                }
            }
        }
            
       for(auto it : st){
            result.push_back(it);
       }
        return result;
    }
};