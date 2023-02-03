#include<bits/stdc++.h>
using namespace std;


int majorityelement(vector<int>& nums){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int maj = nums[n/2];
    int feq=0;
    for(int i =0;i<n;i++){
        if(nums[i]==maj){
            feq++;
        }
    }
    if(feq>n/2){
        return maj;
    }
    return -1;
}


// The time complexity of this code is O(nlogn)
// Runtime 20 ms
// Memory 19.7 MB



// Explanation:

//1. sort(arr,arr+n);: This line sorts the input array arr in ascending order. The time complexity of the sorting algorithm used here is O(nlogn).

//2. int maj = arr[n/2];: This line assigns the value of the middle element in the array to the variable maj.
// because after sorting if there is an majority element then it will be in middle based on the conditon majority element should be > n/2 

// so consider an array 0f which has 1 2 3 2 2 4 2  so after sorting it will be  1 2 2 2 2 3 4 so the n/2 is 3 and if we see clearly the majority element is 2 and is located at pos arr[n/2]==arr[3]

//3. int feq=0;: This line declares a variable feq and initializes it to 0. feq is used to keep track of the frequency of the majority element in the array.

//4. for(int i=0;i<n;i++): This line starts a for loop that iterates over all elements in the array.

//5. if(arr[i]==maj): This line checks if the current element of the array is equal to the majority element maj.

//6. feq++;: If the current element is equal to the majority element, feq is incremented by 1.

//7. if(feq>n/2): This line checks if the frequency of the majority element maj is greater than n/2.

//8. return maj;: If the frequency of the majority element is greater than n/2, then maj is returned as the majority element.

//9. return -1;: If the frequency of the majority element is not greater than n/2, then -1 is returned, indicating that there is no majority element in the array.