class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int num:target){
            mp[num]++; //  add the numbers to the map
        }

        for(int num:arr){
            if(mp.find(num)==mp.end()) return false; // if the number is not present in the arr then it will not be in the map hence the arr will never be equal to target  so return false;

            mp[num]--; // we get the number in the map and reduce it counts
            if(mp[num]==0){ 
                mp.erase(num); // if there is any num whose freq is 0 then erase it from the map
            }
        }
        return mp.size()==0; // check if the map is empty, if it is then all the elements matched and hence can be reversed, else all the elements were not the same
        
    }
};
