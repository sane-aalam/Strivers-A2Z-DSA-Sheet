#include<bits/stdc++.h>
using namespace std;


// 1 → DP solution [ Using Recursion ]
//   → Express Everything in terms of index
//   → Do all the stuff on that index
//   → According to quesiton [find min, max, sum-up,longest, shortest,total number of ways]


#include<bits/stdc++.h>
using namespace std;

int FibonacciNumber(int index){
    if(index == 0){
        return 0;
    }

    if(index == 1){
        return 1;
    }

   return FibonacciNumber(index-1) + FibonacciNumber(index-2);
}

int main()
{

        int n;
        cin >> n;
        int NFibonacciNumber = FibonacciNumber(n);
        cout << NFibonacciNumber << endl;
        return 0;
}

/* 

2 → DP solution [memorization]
  → Identification of overlapping problems 
  → Reduce the overlapping recursive calls 
  → Create Array/Matrix using changeable variables
  → Store the recursive calls
  → Re-use the recursive calls

*/

3 → DP solution [Tabulation]
  → Create matrix/Array using changeable variables
  → convert the base conditon into initialization of DP array/Matrix
  → Copy the recurrance relation [fill using itrative way]

4 → DP solution [ Optimizing Space complexity ]
  → If you don't know space Optimization, you don't know DP.
  → According to question, indetify do you really need array or matrix?
  → Eeither You can just need Last Two value
  → prev_value1 and prev_value2, to Calculate current_value 
  → Inorder to remove the extra space complexity
  → we can use DP on space Optimization.

int FibonacciNumber(int index,vector<int> &dp){
    if(index == 0){
        return 0;
    }

    if(index == 1){
        return 1;
    }

    if(index == 2){
        return 1;
    }

    if(dp[index] != -1){
        return dp[index];
    }

    int lastElement = FibonacciNumber(index-1,dp);
    int secondLastElement = FibonacciNumber(index-2,dp);
    return  dp[index] = lastElement + secondLastElement;
}

int main()
{

        int n;
        cin >> n;
        vector<int> dp(n+1,-1);
        int NFibonacciNumber = FibonacciNumber(n,dp);
        cout << NFibonacciNumber << endl;
        return 0;
}

// Solution-3 tabulation code 

#include<bits/stdc++.h>
using namespace std;

int main()
{

        int n;
        cin >> n;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        cout << dp[n] << endl;
        return 0;
}

// Solution-4 Optimizing Space complexity for a DP solution 
#include<bits/stdc++.h>
using namespace std;

int main()
{

        int n;
        cin >> n;
        int prev_i = 1;
        int prev2_i = 0;

        for(int i = 2; i<=n; i++){
            int curr_i = (prev_i + prev2_i) % 1000000007;
            prev2_i = prev_i;
            prev_i = curr_i;
        }

        cout << prev_i << endl;
        
        return 0;
}