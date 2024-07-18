/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        // Two poiter Algorithm - in-place method 
        for(int j = 1; j< nums.size(); j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};