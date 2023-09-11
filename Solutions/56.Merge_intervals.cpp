class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> merged;

        vector<int> current_interval = intervals[0];


        for(int i =1;i<intervals.size();i++){
            vector <int> next_interval = intervals[i];

            if(current_interval[1]>=next_interval[0]){
                current_interval[1]=max(current_interval[1],next_interval[1]);
            }
            else{
                merged.push_back(current_interval);
                current_interval=next_interval;
            }
        }
        merged.push_back(current_interval);
        return merged;
        
    }
};


/*
Explanation:
1. Sort the intervals based on the start time
2. Create a vector of vector to store the merged intervals
3. Create a vector to store the current interval
4. Iterate through the intervals
5. If the current interval's end time is greater than the next interval's start time, then update the current interval's end time to the max of current interval's end time and next interval's end time
6. Else, push the current interval to the merged vector and update the current interval to the next interval
7. Push the current interval to the merged vector
8. Return the merged vector

DRY RUN :
intervals = [[1,3],[2,6],[8,10],[15,18]]
merged = []
current_interval = [1,3]

i = 1
next_interval = [2,6]
current_interval[1] = 3
next_interval[0] = 2
current_interval[1] = max(3,6) = 6

i = 2
next_interval = [8,10]
current_interval[1] = 6
next_interval[0] = 8
merged = [[1,6]]
current_interval = [8,10]

i = 3
next_interval = [15,18]
current_interval[1] = 10
next_interval[0] = 15
merged = [[1,6],[8,10]]
current_interval = [15,18]

merged = [[1,6],[8,10],[15,18]]
return merged

Time Complexity : O(nlogn) + O(n) = O(nlogn)    
Space Complexity : O(n)




*/