#include<bits/stdc++.h>
using namespace std;

// Solution1 - Recursive code

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

// Solution-2 Memorization of recursive code

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