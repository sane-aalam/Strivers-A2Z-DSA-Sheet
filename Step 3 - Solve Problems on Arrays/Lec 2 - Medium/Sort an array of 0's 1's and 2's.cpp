void sort012(int *arr, int n)
{
    int start = 0;
    int middle = 0;
    int end = n - 1;

    while(middle <= end){
        if(arr[middle] == 0 ){
            swap(arr[middle],arr[start]);
            middle++;
            start++;
        }else if(arr[middle] == 1){
            middle++;
        }else if(arr[middle] == 2){
            swap(arr[middle],arr[end]);
            end--;
        }
    }
}