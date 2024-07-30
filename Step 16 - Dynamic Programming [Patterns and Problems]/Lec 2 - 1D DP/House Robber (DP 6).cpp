
/*
House Robber -1 Code → DP solution [ Optimizing Space complexity ]
  → If you don't know Space Optimization, you don't know DP.
  → According to the question, do you really need an array or matrix?
  → Either You can just need Last Two value
  → prev_value1 and prev_value2, to Calculate current_value
  → Inorder to remove the extra space complexity
  → we can use DP on space Optimization.
*/

#include <bits/stdc++.h> 
long long int HouseRobberFunction(vector<int>& arr) {
        long long int n = arr.size();
        
         long long int prev_i = arr[0];
         long long int prev2_i = 0;
         long long int curr_i = 0;

        for(long long int i = 1; i<arr.size(); i++){
             long long int pick = arr[i];
            if (i > 1)
                  pick += prev2_i;
             long long int notPick = 0 + prev_i;
            // maximum amount of money you can rob tonight
            curr_i = max(pick,notPick);
            prev2_i = prev_i;
            prev_i = curr_i;
        }
        return prev_i;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
        vector<int> temp1;
        vector<int> temp2;
        int n = valueInHouse.size();
        if(n==1)
        return valueInHouse[0];
    
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(valueInHouse[i]);
            if(i!=n-1) temp2.push_back(valueInHouse[i]);
        }

        // →  All houses at this place are arranged in a circle.
        // → That means the first house is the neighbour of the last one
        // → it will automatically contact the police if two adjacent houses were broken into on the same night.

        long long int SkipFirstElementResult = HouseRobberFunction(temp1);
        long long int SkipLastElementResult = HouseRobberFunction(temp2);
        long long int maximumProfitRobber =  max(SkipFirstElementResult,SkipLastElementResult);
        return maximumProfitRobber;
}