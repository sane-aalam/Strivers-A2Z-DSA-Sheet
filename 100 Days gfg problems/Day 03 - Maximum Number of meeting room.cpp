

//* # problem statement - https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>> tempArray;
        
        for(int i = 0; i<n; i++){
            // on base of ending time perform algorithm 
            tempArray.push_back({end[i],start[i]});
            // tempArray.first = endTime
            // tempArray.second = startTime
        }
        sort(tempArray.begin(),tempArray.end());
        
        // becuase one possible can be meeting fix 
        // start with index -1 
        int MaximumNumberMeetings = 1;
        int LastMeetingTime = tempArray[0].first;
            
         for(int i=1;i<n;i++){
                if(tempArray[i].second > LastMeetingTime){
                    LastMeetingTime = tempArray[i].first;
                    MaximumNumberMeetings++;
                }
        }
        return MaximumNumberMeetings;
    }
};