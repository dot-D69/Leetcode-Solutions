class Solution {
public:
    int LCM(int x, int y){
        return (x*y)/gcd(x,y);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res; // We will use this to add the merged numbers and to maintian the order

        for(int n : nums){

            while(!res.empty()){ //If res is not empty then we will check for conditions
                int prev = res.back(); //If not empty so we will thake one num from the vector
                int curr = n ;//This is the number we are on 
                //Prev and curr are adjacent in the nums vector
                if(gcd(prev,curr) == 1) break; //It does not matches the condition so we break out and the curr num gets added to the res
                res.pop_back();
                int LCM = lcm(prev,curr);
                n = LCM;
            }
            //Else it maybe empty so we add the num to it 

            res.push_back(n);
        }
        return res;
    }
};

/*

So How does it Works?

What the Code Does:

Think of res as a stack (a growing list where we can look at the "last pushed" number).
We go through each number n in nums.
For each number:
We check the last number in res (let’s call it prev).
If gcd(prev, n) == 1 → they are coprime → stop merging → push n.
If gcd(prev, n) > 1 → they are not coprime → pop prev, merge them using LCM, and make this new LCM the new n.
Repeat the check until res is empty or the last number and n are coprime.
Push the final n into res.
At the end, res is our result.

The key idea:
res keeps numbers in order.
Whenever two adjacent numbers are not coprime, we fuse them into their LCM.

Dry Run Example

nums = [6, 4, 3, 2, 7, 6, 2]

Step 1: Start
res = []


Step 2: n = 6
res is empty → push 6
res = [6]


Step 3: n = 4
Look at prev = 6, curr = 4
gcd(6,4) = 2 > 1 → not coprime → merge
lcm(6,4) = 12
Pop 6, now n = 12
res is empty → push 12
res = [12]


Step 4: n = 3
Look at prev = 12, curr = 3
gcd(12,3) = 3 > 1 → merge
lcm(12,3) = 12
Pop 12, now n = 12
res is empty → push 12
res = [12]


Step 5: n = 2
Look at prev = 12, curr = 2
gcd(12,2) = 2 > 1 → merge
lcm(12,2) = 12
Pop 12, now n = 12
res is empty → push 12
res = [12]


Step 6: n = 7
Look at prev = 12, curr = 7
gcd(12,7) = 1 → coprime → stop merging
Push 7
res = [12, 7]


Step 7: n = 6
Look at prev = 7, curr = 6
gcd(7,6) = 1 → coprime → stop merging
Push 6
res = [12, 7, 6]


Step 8: n = 2
Look at prev = 6, curr = 2
gcd(6,2) = 2 > 1 → merge
lcm(6,2) = 6
Pop 6, now n = 6
Look at new prev = 7, curr = 6
gcd(7,6) = 1 → stop merging
Push 6
res = [12, 7, 6]


Final Result
res = [12, 7, 6]

*/