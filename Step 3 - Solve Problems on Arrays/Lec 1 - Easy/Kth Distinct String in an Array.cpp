class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string,int> mp;
        for(auto &it : arr){
            mp[it]++;
        }

        int count = 0;
        for(string & str : arr){
            // A distinct string is a string that is present only once in an array.
            if(mp[str] == 1){
                count++;
                if(count == k){
                    return str;
                }
            }
        }
        return "";
    }
};