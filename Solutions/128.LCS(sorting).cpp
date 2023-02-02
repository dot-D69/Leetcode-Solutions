#include <bits/stdc++.h> 
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    int Seq_Len =1;
    int Max_Len =1;
    for(int i =1;i<arr.size();i++){
        if(arr[i]==arr[i-1]+1){
            Seq_Len++;
        }
        else if(arr[i]==arr[i-1]){
            continue;
        }
        else{
            Seq_Len=1;
        }
        Max_Len = max(Max_Len,Seq_Len);
    }
    return Max_Len;
}


// Time Complexity  O(nlogn)
// Runtime  65 ms
// Memory 33.8 Mb





// Explanation of th e above code:

//1. int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) - This line declares a function named lengthOfLongestConsecutiveSequence that takes a vector of integers named arr and an integer named n as input parameters. The function returns an integer.

//2. sort(arr.begin(),arr.end()); - This line sorts the elements of the input vector arr in ascending order. The sort function is a standard library function that is used to sort elements in a container.

//3. int Seq_Len =1; - This line declares an integer variable Seq_Len and sets its initial value to 1. Seq_Len will be used to store the length of the current consecutive sequence.

//4. int Max_Len =1; - This line declares an integer variable Max_Len and sets its initial value to 1. Max_Len will be used to store the length of the longest consecutive sequence.

//5. for(int i =1;i<arr.size();i++) - This line starts a for loop, which iterates over the elements of the input vector arr. The variable i is used as the index of the elements in the vector. The loop continues until i is equal to the size of the vector arr.

//6. if(arr[i]==arr[i-1]+1){ - This line checks if the current element (arr[i]) is equal to the previous element (arr[i-1]) plus 1. If it is, the code inside the curly braces is executed.

//7. Seq_Len++; - This line increments the value of Seq_Len by 1.

//8. else if(arr[i]==arr[i-1]){ - This line checks if the current element (arr[i]) is equal to the previous element (arr[i-1]). If it is, the code inside the curly braces is executed.

//9. continue; - This line skips the rest of the code inside the for loop and continues with the next iteration.

//10. else{ - This line is executed if the current element (arr[i]) is not equal to the previous element (arr[i-1]) plus 1 or equal to the previous element (arr[i-1]).

//11. Seq_Len=1; - This line sets the value of Seq_Len to 1, as a new consecutive sequence has started.

//12. Max_Len = max(Max_Len,Seq_Len); - This line updates the value of Max_Len to be the maximum between its current value and the value of Seq_Len.

//13. return Max_Len; - This line returns the final value of Max_Len, which is the length of the longest consecutive sequence in the input vector arr.