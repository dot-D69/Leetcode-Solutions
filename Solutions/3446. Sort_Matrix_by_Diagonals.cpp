class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int,vector<int>> mp;
        unordered_map<int, int> pos; // consumption index per diagonal (key -> next index)


        // All diagonal elements have the same [i-j] , so we map all the diagonal elements to their diag-i-j values
        // 0 : {1,8,6}
        //-1 : {7,2}
        // 1 : {9,5}
        // -2 : {3}
        //2 : {4}
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }

    //If we just observe every element whose diag value i.e (i-j) is greater than 0 comes under bottom left triangle (decreasing order sort)
    // And every ele whose (i-j)<0 comes under the top right triangle (increasing order sort)
        for(auto &it : mp){
            int key = it.first;

            if(key>=0){
                sort(it.second.rbegin(), it.second.rend());
            }
            else{
                sort(it.second.begin(), it.second.end());
            }
            pos[key] = 0; // next use index starts at 0
            
        }

        vector<vector<int>> res(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int key = i-j;
                res[i][j] = mp[key][pos[key]];
                pos[key] += 1;
            }
/*
mp is a map: map<int, vector<int>>.
mp[key] is the vector of numbers stored at this diagonal.
Example: mp[0] = {8,6,1}.
pos is a map of cursors: unordered_map<int,int>.
pos[key] is the index of the next unused element from that diagonal vector.

Now to fill our res we use mp[key][pos[key]];
How does it works : key =0;
mp[0] = {8,6,1}
pos[0] = 0;
mp[0][0] =  it will return the first element of the vector in the map i.e 8
then we do pos[key]++;
which makes pos[0] =1 ;

Now when next time key = 0
res[i][j] = mp[key][pos[key]];
mp[0] = {8,6,1}
pos[0] = 1;
mp[0][1] = it will give the second element of the vector in the map i.e 6
pos[key]++ ; ----> pos[0] = 2;

Similarly it will work for all the key and indexes and we don't have to delete the element
*/
        }
        return res;

    }
};

/*
How is it better than the previous erasse solution:

mp[key].front() → O(1) (just read first element).

erase(mp[key].begin()) → O(L), where L = size of the vector, because all remaining elements have to shift left by 1.

So, if a diagonal has length L, erasing L times takes: O(L) + O(L-1) + O(L-2) + ... + O(1) = O(L^2)

Now, the matrix has ~n² elements in total, spread across diagonals.
The worst-case diagonal length is n, and there are 2n-1 diagonals.

So the total worst-case time complexity becomes: O( Σ L^2 for all diagonals )
≈ O(n³)   (because diagonals of length ~n dominate)
That means for a 100x100 matrix, you could hit ~1,000,000 operations just from refilling.



How does the extra map with key solves this:

mp[key][pos[key]] → O(1) (direct index access into vector).

pos[key]++ → O(1).

No erasing, no shifting, no hidden loops.

So filling the entire matrix (with n² cells) costs: O(n²logn) (as there is sorting also)
That’s optimal: every element is written exactly once.


*/


