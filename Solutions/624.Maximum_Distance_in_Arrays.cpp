class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // since the array are sorted so the first element would be small and the last one would be greater
        int MIN = arrays[0].front();   // we take the first ele of first array as min ele
        int MAX = arrays[0].back();   // Take the last of ele of the first array as max ele

        int result =0;   // to Store the ans

        for(int i=1;i<arrays.size();i++) {  // start from the 2nd array
            int currMin = arrays[i].front(); // maintain a current min for the array we are on
            int currMax = arrays[i].back();  // maintain a current max for the array we are on

            result = max({result, abs(MAX - currMin), abs(MIN - currMax)}); // it  will get us the maximum distance in the arrays

            // update the Max and Min for next use

            MAX = max(currMax, MAX); 
            MIN = min(currMin, MIN);
        }
        return result;
    }
};

// Time Complexity: O(N)
// Space Compexity: O(1)

/*Note :
/The curly braces in the statement:
result = max({result, abs(MAX - currMin), abs(MIN - currMax)});

are used to create an initializer list in C++. The max function can accept two arguments by default, but with the use of an initializer list (curly braces), you can pass multiple values to the max function, and it will return the maximum value among all the elements in the initializer list.

In this case, the initializer list {result, abs(MAX - currMin), abs(MIN - currMax)} is passed to the max function, allowing it to compare all three values (result, abs(MAX - currMin), and abs(MIN - currMax)) and return the largest one.
*/