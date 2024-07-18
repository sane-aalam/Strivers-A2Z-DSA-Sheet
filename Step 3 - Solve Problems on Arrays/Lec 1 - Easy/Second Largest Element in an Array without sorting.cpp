class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int firstMaximumElement = -1;
	    int secondMaximumElement = -1;
	    
	    for(int index = 0; index < n; index++){
	        if(arr[index] > firstMaximumElement){
	            
	             // second student assign the value of firststudent rank 
	            // first student assign new value(High value)
	           secondMaximumElement = firstMaximumElement; // assign first student marks into the second student
	            firstMaximumElement = arr[index];          // second student gets maximum marks, so udpate with current_value
	         
	        }else if(arr[index] < firstMaximumElement && arr[index] > secondMaximumElement){
	        
	        // what if you currentElement is smaller to the firstElement,
	       // and also greater to the nextElement,Then you can easy update
	       // the value of the secondElementMaximum
	            secondMaximumElement = arr[index];
	       }
	    }
	    
	    return secondMaximumElement;
	}
};