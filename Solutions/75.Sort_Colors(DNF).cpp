class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// The Dutch National Flag Algorithm (DNF)
/*
what it says is that we will take three pointers low, mid and high in an array of size n
There are 3 rules
i.) from index 0 to low-1 everything is 0,
ii.) from index low to mid-1,everything is 1,
iii.) from index high+1 to n-1

so now the indexes mid to high contained unsorted numbers 0/1/2;

now we have to follow the  rules and sorted the unsorted part of the array

we can have both low and mid at 0 depedndign on the array (basically from the index where everythiing is unsorted 0/1/2 we will take mid from there and till high) let's say for the array
[0,1,1,0,1,2,1,2,0,0,0] the low is at [0] the mid is [0] and high is at [n-1]


now we will check
 if arr[mid] = 0;
 swap(arr[low],arr[mid])
 left++;
 mid++;

 if(arr[mid]==1)
 mid++;

 if(arr[mid]==2)
 swap(arr[mid],arr[high])
 high++;

 when mid crosses high (mid>high) we stop and then we will have a sorted array


*/