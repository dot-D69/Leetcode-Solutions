class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum =0;
        int maxlen=0;

        for(int i =0;i<n;i++){
            if(nums[i]==0){
                sum-=1;
            }
            else{
                sum+=1;
            }

            if(sum==0){
                maxlen=i+1;
            }
            else if(mp.find(sum)!=mp.end()){
                maxlen = max(maxlen,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }

        }
        return maxlen;
        
    }
};


/*
Explanation:



1. We initialize an unordered map `mp` to keep track of the sum and its index.
2. We initialize `sum` and `maxlen` to 0.
3. We iterate through the input array:
    - If the current element is 0, we decrement `sum` by 1.
    - If the current element is 1, we increment `sum` by 1.
    - If `sum` is 0, we update `maxlen` to `i + 1`. This is because the subarray from the beginning to the current index has equal number of 0s and 1s.
    - If `sum` is not 0, we check if `sum` is already in the map. If it is, we update `maxlen` to the maximum of its current value and `i - mp[sum]`. This is because the subarray between the current index and the index where `sum` was first encountered has equal number of 0s and 1s.
    - If `sum` is not in the map, we add it to the map with its index as the value.
4. We return `maxlen`.

Dry Run:



Input: [0,0,0,1,1,1,1,0]

Initialize variables:

Loop through input array:

At i = 0, nums[0] is 0, so subtract 1 from sum, making sum -1.
sum = -1
check if sum is present in map, it is not
add sum to map with index 0
maxlen remains 0
Continue the loop:

At i = 1, nums[1] is 0, so subtract 1 from sum, making sum -2.
sum = -2
check if sum is present in map, it is not
add sum to map with index 1
maxlen remains 0
Continue the loop:

At i = 2, nums[2] is 0, so subtract 1 from sum, making sum -3.
sum = -3
check if sum is present in map, it is not
add sum to map with index 2
maxlen remains 0
Continue the loop:

At i = 3, nums[3] is 1, so add 1 to sum, making sum -2.
sum = -2
check if sum is present in map, it is 
update maxlen to max(maxlen, i - mp[sum]) = max(0, 3 - 1) = 2

At i = 4, nums[4] is 1, so add 1 to sum, making sum -1.
sum = -1
check if sum is present in map, it is
update maxlen to max(maxlen, i - mp[sum]) = max(2, 4 - 0) = 4

At i = 5, nums[5] is 1, so add 1 to sum, making sum 0.
sum = 0
update maxlen to i + 1 = 6

At i = 6, nums[6] is 1, so add 1 to sum, making sum 1.
sum = 1
check if sum is present in map, it is not
add sum to map with index 6
maxlen remains 6

At i = 7, nums[7] is 0, so subtract 1 from sum, making sum 0.
sum = 0
update maxlen to i + 1 = 8

Return maxlen = 8
s
*/
