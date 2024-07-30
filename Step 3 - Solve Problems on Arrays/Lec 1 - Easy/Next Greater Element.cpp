
//---------------Stack Implementation code-----------------

// Stack is empty Then push -1 into the stack
// sTack Top Element is greater to array element, Then push stack Top element 
// STack Top Element is not greater 
//    case-1 Pop the stack element until you got maximum element 
//    case-2 Po the stack element until stack is gonna to empty 

#include <stack>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	// Write your code here
	vector<int>result;
	stack<int>st;

	int size =arr.size();
	for(int i =size-1;i>=0;i--){
		if(st.empty()){
			result.push_back(-1);
		}else if(!st.empty() && st.top()<=arr[i]){
			while(!st.empty() && st.top() <= arr[i] ){
				st.pop();
			}
			if(st.empty()){

				result.push_back(-1);
			}else{
			

				result.push_back(st.top());
			}
		}
	 // When stack element is greater than arr element 
		else{
			result.push_back(st.top());
		}
		st.push(arr[i]);
	}
	reverse(result.begin(), result.end());
	return result;
}