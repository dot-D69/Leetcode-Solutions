class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int  n = points.size();
        int count =0;
        auto lambda = [](vector<int> point1, vector<int> point2 ){ 
            if(point1[0]==point2[0]){
                return point1[1] > point2[1];
            }
        return point1[0]<point2[0];
        };
        sort(points.begin(),points.end(),lambda);

        for(int i=0;i<n;i++){
            int Alice_x = points[i][0];
            int Alice_y = points[i][1];

            int MaxY = INT_MIN;

            for(int j=i+1;j<n;j++){
                int Bob_x =points[j][0];
                int Bob_y = points[j][1];

                if (Bob_y >Alice_y){
                    continue;
                    
                }

                if(Bob_y >MaxY){
                    count++;
                    MaxY = Bob_y;
                }
                
            }
        }
        return count;
    }
};

/*

It is Baiscally the same solution as the first part of this question :https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/

The only thing different is the constraint: 2 <= n <= 1000
The brute force will not work on it O(n^3)

So wee need to come up with a better solution which we did so Time Complexity of our solution is : O(n^2)

The explanation for the code is same as the code in the first part

You can find the explanation here : https://github.com/dot-D69/Leetcode-Solutions/blob/main/Solutions/3025.%20Find_the_Number_of_Ways_to_Place_People_I(Better).cpp



*/
