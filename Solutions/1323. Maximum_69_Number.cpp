class Solution {
public:
    int maximum69Number (int num) {
        
        string nums = to_string(num);
        for(int i=0;i<nums.size();i++){
            if(nums[i]=='6'){
                nums[i]='9';
                break;
            }
        }
        int res = stoi(nums);
        return res;
    }
};

/*
1. To iterater over the num , we first convert it to string
2. Now the logic is to find the max num we don't need to change the 9, we only need to change 6, as changing 9 will oly decrese he value
3. Now in that also we don't need to check every '6'  digit to change, since it is said maximum ,we just need to flip the 6 at highest place like: thousands or hundreds or tens , whichever comes first|
4. So basically we need to change the first 6 we find , it can be at any place , but we only need to change the first "6" that we encounter, as it will automatically change the num to it's max value .
5. Example :  9669 -> if we just change the ifrst 6 it becomes-> 9969 , then just return no need to check any other  digit

6. Before returning we need to change back to int using stoi() as the return type is an int






Time Complexity Analysis
Let’s break it down step-by-step:

1. Converting int to string:
to_string(num) processes all digits.

For up to 5 digits, this is O(n), where n is the number of digits (here, n ≤ 5).

2. For loop to scan digits:
Loops at most n times (worst case: no '6' in the string).

If it finds a '6', breaks early—so in most cases, it doesn't finish the loop.

3. String to int conversion:
stoi(nums)—again, O(n), since it parses every digit.

Total Time Complexity:
O(n) for string conversion + O(n) for loop + O(n) for stoi.

Combine: O(n), where n is the number of digits (max 5).

But for this problem:
Since n ≤ 5, it’s essentially O(1) for practical purposes.

*/