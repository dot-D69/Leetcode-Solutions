class Solution {
public:
    int n;
    vector<vector<int>> t; // memoization 

    int childFirst(vector<vector<int>>& fruits){
        int count =0;
        for(int i=0;i<n;i++){
            count+= fruits[i][i]; // all diagonal elements
        }
        return count;
    }

    int childSecond(int i, int j ,vector<vector<int>>& fruits ){

        //Base case
        if(i>=n || j<0 || j>=n){
            return 0;
        }

        if(i==n-1 && j==n-1){
            return 0;
        }

        if(i==j || i>j){
            return 0;
        }

        if(t[i][j]!=-1){
            return t[i][j]; // if already computed the values then just return , no need to compute the same value again
        }

        int bottom_left = fruits[i][j] + childSecond(i+1,j-1,fruits);
        int bottom = fruits[i][j] + childSecond(i+1,j,fruits);
        int bottom_right = fruits[i][j] + childSecond(i+1,j+1,fruits);

        return t[i][j]=max({bottom_left,bottom,bottom_right}); // store result in the cache so that, don't have to calculate again
    }

    int childThird(int i, int j ,vector<vector<int>>& fruits ){

        //Base case
        if(i>=n || j<0 || j>=n){
            return 0;
        }

        if(i==n-1 && j==n-1){
            return 0;
        }

        if(i==j || i<j){
            return 0;
        }

        if(t[i][j]!=-1){
            return t[i][j];
        }

        int bottom_left_3 = fruits[i][j] + childThird(i-1,j+1,fruits);
        int bottom_3 = fruits[i][j] + childThird(i,j+1,fruits);
        int bottom_right_3 = fruits[i][j] + childThird(i+1,j+1,fruits);

        return t[i][j] = max({bottom_left_3,bottom_3,bottom_right_3});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        t.resize(n,vector<int> (n,-1)); // intialize the memoization cache

        //First child
        int c1 = childFirst(fruits);

        //Second child
        int c2 = childSecond(0,n-1,fruits);

        //Third child
        int c3 = childThird(n-1,0,fruits);

        return c1+c2+c3;

    }
};