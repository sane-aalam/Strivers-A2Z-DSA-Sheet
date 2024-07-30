#include <bits/stdc++.h> 

void rearrange(vector<int> &arr)
{
	// Write your code here.
	vector<int> neg;
	vector<int> pos;

	for(int i = 0; i<arr.size(); i++){
		if(arr[i] < 0){
			neg.push_back(arr[i]);
		}else{
			pos.push_back(arr[i]);
		}
	}
	
// If positives are lesser than the negatives.
// According to size of array
// Konsa array bada hai 
// Negative wala zada to meansing remaning element negative push karne hoge
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      arr[2*i] = pos[i];
      arr[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        arr[index] = neg[i];
        index++;
    }
  }
  // If negatives are lesser than the positives.
  // means - postive element remaning push karne honge
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      arr[2*i] = pos[i];
      arr[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        arr[index] = pos[i];
        index++;
    }
  }
}
