class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            k++;
        }
        return k;
    }
};

// To remove all the occurences of a particular element from the vector we can use the erase-remove idiom.

//  let's break downn line no. 4

/*
i.) values.begin() returns an iterator pointing to the beginning of the vector values.
ii.) values.end() returns an iterator pointing just past the end of the vector values.
iii.) remove(values.begin(), values.end(), val) is an algorithm that shifts the elements that are not equal to val towards the beginning of the range and returns an iterator pointing to the new logical end after the "removed" elements.
iv.) values.erase(..., values.end()) removes the elements from the iterator returned by std::remove to the end of the vector values.
*/

/*
Consider the example vector: {2, 3, 4, 2, 5, 2, 6, 2} and you want to remove all occurrences of  val = 2.

1.) remove Algorithm:
When you use std::remove(values.begin(), values.end(), val), the algorithm processes the elements in the following way:

Initial state: {2, 3, 4, 2, 5, 2, 6, 2}
Processed state: {3, 4, 5, 6, 5, 2, 6, 2}
The algorithm has shifted all non-matching elements (3, 4, 5, 6) towards the beginning of the vector, and the last two elements (2, 2) are unspecified at this point. The extra 4 and 5 you mentioned are a result of this shifting process.

2.) The Unspecified Elements:
After the remove algorithm, the order of elements beyond the new logical end is unspecified. In the example, you see the 4 and 5 because they were shifted from their original positions by the remove algorithm. These values are essentially "leftover" values from the shifting process, and you should not rely on their specific values.

3.) erase Method:
To actually remove these unspecified elements and finalize the operation, you would use the erase function

This combination of remove and erase effectively removes the unspecified elements and adjusts the size of the container, resulting in the desired state: {3, 4, 5, 6}.
*/