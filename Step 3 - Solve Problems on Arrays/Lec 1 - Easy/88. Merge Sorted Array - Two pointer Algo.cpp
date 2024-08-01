class Solution {
public:
    // Two pointer Algorithm
    // Pratice makes perfect!
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = m-1;
        int j = n-1;
        // push the Element into the back Index
        // According to maximum element,Which element is maximum (nums1,nums2)
        int backIndexPosition = m+n-1;
        
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[backIndexPosition] = nums1[i];
                i--; 
                backIndexPosition--;
            }
            else{
                nums1[backIndexPosition] = nums2[j];
                j--; 
                backIndexPosition--;
            }
        }
        while(j>=0){
            nums1[backIndexPosition] = nums2[j];
            j--; 
            backIndexPosition--;
        }   
    }
};