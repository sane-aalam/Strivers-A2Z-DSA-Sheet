#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    int i = 0;
    int j = 0;

   deque<int> q;
    vector<int> result;

    while(j < nums.size()){
// smaller element pop into the queue
// push next element into the queue
        while(!q.empty() && q.back()<nums[j]) 
             q.pop_back();
             q.push_back(nums[j]);

// Indentify window size of k
        if((j - i + 1) < k){
            j++;
        }
// When Hit the window (j-i+1) 
//    1. do calculation according to questions
//    2. slide window of size k 
        else if(j - i + 1 == k){
             
             // calculation
             result.push_back(q.front());
             if(q.front() == nums[i]){
                 q.pop_front();
             }
             // slide the window
            i++;
            j++;
        }
    }
    return result;
}
