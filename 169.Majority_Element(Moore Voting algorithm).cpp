#include<bits/stdc++.h>
using namespace std;

int majorityelement(vector<int>& nums){
    int n = nums.size();
    int candidate = nums[0];
    int votes = 1;

    for(int i=0;i<n;i++){
        if(nums[i]==candidate){
            votes++;
        }
        else{
            votes--;
        }
        if(votes==0){
            candidate=nums[i];
            votes=1;
        }
    }
    return candidate;
}

// Time complexity of this code is O(n)


// This is the Boyer-Moore Majority Vote algorithm

/*Boyer-Moore Majority Vote algorithm is an algorithm for finding the majority element in an array of elements. The algorithm makes use of two variables, a candidate and a votes. It iterates through the array, updating the candidate and votes as it goes. If the current element is equal to the candidate, it increments the votes, otherwise, it decrements the votes. If the votes reaches zero, it updates the candidate to be the current element and resets the votes to 1. After the iteration, the final candidate is returned as the majority element, if it is indeed a majority element. The time complexity of this algorithm is O(n) because it only iterates through the array once.*/



// Explanation:

//1. int n = nums.size();: This line gets the number of elements in the input vector nums.

//2. int candidate = nums[0];: This line initializes the first element of the nums vector as the candidate element.

//3. int votes=0;: This line initializes a variable votes to keep track of the number of times the current candidate has appeared.

//4. for(int i =0;i<n;i++){: This line starts a for loop that will iterate n times, where n is the size of the input vector.

//5. if(nums[i]==candidate){: This line checks if the current element in the nums vector is equal to the candidate.

//6. votes++: If the current element is equal to the candidate, this line will increment the number of votes for the candidate.

//7. else{: If the current element is not equal to the candidate, this line will start the else block.

//8. votes--;: This line decrements the number of votes for the current candidate.

//9. if(votes==0){: This line checks if the number of votes for the current candidate has become zero.

//10. candidate=nums[i];: If the number of votes has become zero, this line sets the next element of the nums vector as the new candidate.

//11. votes =1;: This line resets the number of votes to 1 for the new candidate.

//12. return candidate;: This line returns the final candidate element that appeared the most number of times in the nums vector