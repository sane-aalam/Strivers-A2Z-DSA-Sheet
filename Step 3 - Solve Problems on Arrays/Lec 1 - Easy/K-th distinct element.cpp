// K-th distinct element

class Solution{
	public:
		int KthDistinct(vector<int>nums,int k){
		    // Code here.
		unordered_map<int,int> mp;
		
        for(auto &it : nums){
            mp[it]++;
        }

        int count = 0;
        for(int & num : nums){
            // A distinct Element that is present only once in an array.
            if(mp[num] == 1){
                count++;
                if(count == k){
                    return num;
                }
            }
        }
         return -1;
	}
};