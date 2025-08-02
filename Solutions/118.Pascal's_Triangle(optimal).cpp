class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> result(numRows); // make a result 2d vector or array

        for(int i=0;i<numRows;i++){
            result[i]= vector<int>(i+1,1); // since every row has row+1 column so we fill every row with 1

            for(int j=1;j<i;j++){
                result[i][j] = result[i-1][j]+result[i-1][j-1]; // This is getting the sum of two numbers above the current number
            }
        }
        return result;
        
    }
};


// Explanation;
/*
 The way pascals triangle works is that it adds the sum of the two numbers above it

i=0 -> 1
i=1 -> 1 1
i-2 -> 1 2 1
1=3 -> 1 3 3 1
i=4 -> 1 4 6 4 1
i=5 -> 1 5 10 10 5 1

Now if you see the pattern above so there are two patterns 

1st :
We see that  for each rows the numberof cols are rows +1
for example for row i=0  the col is 1 (0 +1)
for row i=1 the cols are 2(i.e. 1+1) 
for row i=2 the cols are 3 (i.e. 2+1)
and so on, so for each row the cols are rows+1

2nd: 
From row i=2 
The sum of the element is (previous row + diagonal previous row) i.e. for 2 in the row i=2 it comes by adding the 1 above it and the 1 diagonal to it

Similiarly in the row i =3  the element 1,3,3,1 so the 3 comes from  the sum of the 2 above it and the 1 diagonal from it and for the other 3 -> it comes from the 1 above it and the 2 diagonal from it

Again in row i=4 the elements are 1 4 6 4 1: So now the 4 comes from -> Sum of the 3 above it and 1 diagonal from it,
: similarly the 6 comes from -> the 3 above it and the 3 diagonal from it,
: the other 4 comes from -> the sum of the 1 above it and the 3 diagonal from  it

so the patter here is that arr[i] = arr[i-1][j]      +    arr[i-1][j-1]
                            (this is the element above it)   (this is the element diagonal from it)


There is one more obsevation that the starting and the end of each col are alsways we are only calulating the part ion the middle so we will start the col from j = 1 (since the changes are only happeing after the first elemnet so we don't start our colsd from j=0 as it will always be one)

Also the element at end is always 1 so we wont go till the lsst for our cols(This will be more clear in the code)


// Now the code floe
we first make an array with rows = numRows

result = [] [] [] [] [] []

now we start a for lopp to go through the array

The loop goes from i-0 to i< numrows
So  we saw that for each row the number of columns are rows+1

therefore we add this result[i] = vector<int> (i+1) // This is adding a new array inside the array row i=1
And to make things easier we fill all the rows with 1 , hence  result[i] = vector<int> (i+1,1)

So first i will only show you what would the 2d array look like without running the second loop
when i =5

1
1 1
1 1 1
1 1 1 1
1 1 1 1 1

This is what our 2d matrix would be like 

but now if we go through the second loop , the no of cols j starts form 1 and only goes till j<i
why i already told that because the first and the last element will always be 1 , so we don't start from the element and don't go till the last element, the only elements that will change are the ones in between

for i=0 , the second loop won't run since j=1 and j<i   [1]
for i=1 . the second loop stiil won't be executed since j=1 and J should be less than i [1 1]

for i= 2 ( now the loop will run) [1 1 1]
j =1
res[i][j] = res[2][1] ( it points to element 1 at position 2)
res[2][1] = res[1][1]+ res[1][0] ( it adds the 1 above the and the1 diagonal to it form the last row)
j++, the loop ends
row = [1 2 1]

for i =3   [1 1 1 1]
j = 1
res[i][j] = res[3][1] ( this means the element at pos 1 in row 3)
res[3][1] = res[2][1]+res[2][0] ( it adds   the 2 abovr it and the 1 diagoanal from it)
j++ -> j=2
row = [1 3 1 1]

res[3][2] -> ( this means the element at pos 2 in row 3)
res[3][2] = res[2][2]+res[2][1] (it adds the 1 above it and the 2 diagonal from  it)

j++ : The loop ends
row = [1 3 3 1]

similalry for i =4 it works the same way ( adds the element form above and from diagonal , before reaching the last element it ends)

the row will be [1 4 6 4 1]

so our 2d matrix will become
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

This will be our answer and we will return it
*/