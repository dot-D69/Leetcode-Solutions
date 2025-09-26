//Better Approach
//Time Complexity: O(n^2logn)
//The key for this is to sort
//Sicne in a sorted Arrray we just need to ssearch for the element at which a+b>c is vlaid for the last time, that after that index it will become invalid for a+b>c
//ANd to find that index we use binary search since the arry is sorted
class Solution {
public:
    int BSearch(vector<int>& nums, int l,int r, int target){
        int k =-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]<target){
                k=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return k;
    }

    int triangleNumber(vector<int>& nums) { 
        int n = nums.size();
        if(n<3) return 0;
        int count =0;
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;
            for(int j=i+1;j<n;j++){
                int sum = nums[i]+nums[j];
                int k = BSearch(nums,j+1, n-1,sum);
                if(k !=-1){
                    count+=(k-j);
                }
            }
        }
        return count;
    }
};

/*

Why sorting is important here:

The triangle rule says: a + b > c for all sides.
If the array is sorted, c will always be the largest in the triplet, so we only need to check a + b > c once.
Sorting makes it easy to find the last index where this holds true — after that, all bigger numbers will fail.
This is why binary search works: sorted order means all valid c values are before the first invalid one.
Without sorting, you’d have to check all permutations → 
O(n^3) brute force.
Sorting drops it to 
O(n^2 logn)








DRY RUN:

nums = [0, 2, 2, 3, 8]


Sort
Sorted array: [0, 2, 2, 3, 8]
n = 5, count = 0

Outer Loop (i)
i = 0 → nums[i] = 0
if(nums[i] == 0) continue; → skip this iteration ✅ (zero case)
i = 1 → nums[i] = 2
    j = 2 → nums[j] = 2
    sum = 4
    BSearch(l=3, r=4, target=4)
        mid=3 → nums[3]=3 < 4 → k=3, l=4
        mid=4 → nums[4]=8 !< 4 → r=3 → stop
        return k=3 ✅ (valid index)
    count += (3 - 2) = 1 → count=1 (triangle: 2, 2, 3)

    j = 3 → nums[j] = 3
    sum = 5
    BSearch(l=4, r=5, target=5)
        mid=4 → nums[4]=8 !< 5 → r=3 → stop
        return k=-1 ❌ (binary search fail)
    Skip count update

    j = 4 → nums[j] = 8
    sum = 10
    BSearch(l=5, r=5, target=10)
        mid=5 → nums[5]=9 < 10 → k=5, l=6 → stop
        return k=5 ✅
    count += (5 - 4) = 1 → count=2 (triangle: 2, 8, 9)



Next Iteration:
i = 2 → nums[i] = 2
    j = 3 → nums[j] = 3
    sum = 5 → BSearch returns -1 ❌ → skip
    
    j = 4 → nums[j] = 8
    sum = 10 → BSearch returns k=5 ✅ → count += 1 → count=3 (triangle: 2, 8, 9)



NEXT ITERATION:
i = 3 → nums[i] = 3
    j = 4 → nums[j] = 8
    sum = 11 → BSearch returns k=5 ✅ →
    count += 1 → count=4 (triangle: 3, 8, 9)

NEXT ITERATION:
i = 4 → nums[i] = 8
Inner loop runs only for j=5 → but j < n-1 fails → no run

Final Count
count = 4 → Valid triangles:

(2, 2, 3)
(2, 8, 9)
(2, 8, 9)
(3, 8, 9)



*/