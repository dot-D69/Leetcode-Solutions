class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> res;
        map<int, vector<int>> mp;
        
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){

                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for(auto &it : mp){
            if(flip){
                reverse(it.second.begin(), it.second.end());
            }

            for(int i : it.second){
                res.push_back(i);
            }

            flip = !flip;
        }

        return res;

        
    }
};

/*

We can see that whenever such 2D matrix questions are asked there is some sort of pattern that is being followed by question


For diagonals we follow one tip if it is going in  "↗" we use [i+j] and if it is going in "↘" we use [i-j]
Since in this question we are going like "↗" and just flipping we will use [i+j]

Now the pattern if you see closely, then all diagonal elements like {2,4} or{7,5,3} or {6,8}

All the diagonal elements that follow the same diagonal have same [i+j] value

eg: 2 = i+j = (0+1) =1
    4 = i+j = (1+0) = 1

    3 = i+j = (0+2) = 2
    5 = i+j = (1+1) = 2
    7 = i+j = (2+0) = 2

    similarly 6 and 8 have i + j = 3

    So all we need to do is just map all the elements for each of i+j value like:

    0 -> {1}
    1 -> {2,4}
    2 -> {3,5,7}
    3 -> {6,8}
    4 -> {9}

    and then return,
    But before returning we need to alternatively flip each of the arrays
    eg 0 -> flip = {1}
       1 - > not flip  = {2,4}
       2 -> flip  =  {7,5,3}
       3 -> not flip = {6,8}
       4 -> flip = {9}

       This is how we get the diagonally traversed array



*/