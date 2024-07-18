class Solution {
public:
    bool check(vector<int>& nums) {

        int breakpoint = 0;

        /*
        step by step appraoch used 
        1 - if there is more than one breakpoint then you can say 
        array is not sorted and roated 
        3- else array is sorted and rotated 
        */
        int n = nums.size();
        for(int i = 0; i<n; i++){
            //  A[i] == B[(i+x) % A.length]
            if(nums[i] > nums[(i+1)%n]){
                breakpoint ++ ;
            }
        }

        return breakpoint <= 1;
    }
};