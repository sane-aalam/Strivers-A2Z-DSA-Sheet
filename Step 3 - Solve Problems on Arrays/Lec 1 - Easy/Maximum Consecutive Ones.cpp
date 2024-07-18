/* roblem statement
Send feedback
You are given an array ‘ARR’ of length ‘N’ consisting of only ‘0’s and ‘1’s. Your task is to determine the maximum length of the consecutive number of 1’s.

For Example:
ARR = [0, 1, 1, 0, 0, 1, 1, 1], here you can see the maximum length of consecutive 1’s is 3. Hence the answer is 3.
*/


int consecutiveOnes(vector<int>& arr){
    //Write your code here.
    int sizeOfarray = arr.size();

    int maximumConsecutiveOnes = 0;
    int currentConsecutiveOnes = 0;


    for(int currentIndex = 0; currentIndex < sizeOfarray; currentIndex++){
        if(arr[currentIndex] == 1){
            // currentConsecutiveOnes = currentConsecutiveOnes + 1;
            currentConsecutiveOnes++;
            if(currentConsecutiveOnes > maximumConsecutiveOnes){
                maximumConsecutiveOnes = currentConsecutiveOnes;
            }
        }else{
            // When you fond zero (restart the process)
            currentConsecutiveOnes = 0;
        }
    }
    return maximumConsecutiveOnes;
}