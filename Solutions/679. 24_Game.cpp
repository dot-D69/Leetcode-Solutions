class Solution {
public:
double eps = 0.001; // Tolerance for floating-point comparison. To avoid floating point precission errors
    bool solve(vector<double>&nums){
        
        //base case
        if(nums.size()==1){  // check if the size is of vector is 1 , then this is our base case, we wiil return if the element is equal to 24
            return abs(nums[0]-24)<=eps; 
            //See if the value in double is like 23.99999 , so to over come this we use epsilon
// if we subtract 23.9999 and 24 and if the diffrence is lees than epsilon , so we can that the diffrence is almost negligible
// it means both are almost equal so we can just return true is the difference is less than or equal to epsilon

        }

        // Possible ways to pick up two elements, a and b
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j) continue; // if both elements are we skip an move onto next 

                vector<double> temp; // A diff vector , to store the elements that have not been selected
                for(int k=0;k<nums.size();k++){ 
                    if(k!=i && k!=j){ //  We check if the current element is not the selected element a and b.
                        temp.push_back(nums[k]); // Push that element to the vector
                    }
                }

                double a = nums[i]; // a
                double b = nums[j]; // b

                vector<double> operations = {a+b,a-b,b-a,a*b}; // vector to store all the values of the operations
                
                // We need to check 0 , before adding the division operator so that it does not gives error
                if(a>0){
                    operations.push_back(b/a);
                }

                if(b>0){
                    operations.push_back(a/b);
                }
                
// We now check each of the operations value by adding it to  the list of not selected vector Temp
// We will check each of the  operations value if using that gets us 24
// If that particular operation value does not gives us 24, so remove that value and check by adding other operations value
// like we once add: a+b -> temp = [i,j,a+b] -> it does  not gives us 24 then we remove it -> [i,j]
// then we add another operations value: a-b -> temp = [i,j,a-b] -> we again check if the value mathces 24

// We recursively cll the solve fundtion after adding the operations value, so that it checks all the possibilities
// when size of the temp is only one it checks it gives 24 it not we try again with another opertaion value

                for(double op : operations ){
                    temp.push_back(op); // Do
                    if(solve(temp) == true){ // Explore
                        return true;
                    }
                    temp.pop_back(); //undo
                }
            }
        }
        return false;
    }


    bool judgePoint24(vector<int>& cards) {
        vector<double> nums; // first we need to make a vecotr to store the values in double
        for(auto card:cards){ // push value of cards into new vector and typecast each of them into double
            nums.push_back((double)card);
        }

        return solve(nums); // Call the recursice function
    }
};

/*
Dry run example
[3,3,8,8]

it tries every ordered pair (i, j) with i != j.

for that pair a=nums[i], b=nums[j] it tries: a+b, a-b, b-a, a*b, and (since all numbers here are > 0) both divisions b/a and a/b.

base case: when the vector size is 1, return abs(x - 24) <= eps with eps = 0.001

start with [3,3,8,8].

the solver cycles through ordered pairs. the first pair (3,3) leads to many children; none reaches 24 → (also fails).

it reaches the pair (3,8). the key trick is to create 8/3, then make 3 - (8/3) = 1/3, and finally compute 8 ÷ (1/3) = 24.
that’s exactly what the recursion will do on one of its branches


Recursion TREE:

solve([3,3,8,8])
│
├─ Pair (3,3) → remaining [8,8]
│   ├─ op: 3+3 = 6      → solve([8,8,6])      → (also fails)
│   ├─ op: 3-3 = 0      → solve([8,8,0])      → (also fails)
│   ├─ op: 3*3 = 9      → solve([8,8,9])      → (also fails)
│   ├─ op: 3/3 = 1      → solve([8,8,1])      → (also fails)
│   └─ op: 3/3 = 1 (dup)→ solve([8,8,1])      → (also fails)
│
├─ Pair (3,8) → remaining [3,8]
│   ├─ op: 3+8 = 11     → solve([3,8,11])     → (also fails)
│   ├─ op: 3-8 = -5     → solve([3,8,-5])     → (also fails)
│   ├─ op: 8-3 = 5      → solve([3,8,5])      → (also fails)
│   ├─ op: 3*8 = 24     → solve([3,8,24])     → (also fails)
│   ├─ op: a=3, b=8 ⇒ b/a = 8/3 ≈ 2.6666667   →  ✅ follow this branch
│   │
│   │   solve([3,8, 2.6666667])
│   │   │
│   │   ├─ (other pairs/ops one step deep) → (also fails)
│   │   │    e.g., Pair (3,8): 3+8=11 → solve([11,2.6666]) → (also fails)
│   │   │          Pair (3,8): 3*8=24 → solve([24,2.6666]) → (also fails)
│   │   │          Pair (8,2.6666): 8+2.6666 → …           → (also fails)
│   │   │
│   │   └─ Pair (3, 2.6666667) → remaining [8]
│   │       ├─ op: 3+2.6666 = 5.6666  → solve([8,5.6666])   → (also fails)
│   │       ├─ op: 3-2.6666 = 0.3333  →  ✅ follow this
│   │       │
│   │       │   solve([8, 0.3333333])
│   │       │   │
│   │       │   ├─ op: 8+0.3333 = 8.3333  → solve([8.3333]) → base: |8.3333-24|>eps → false
│   │       │   ├─ op: 8-0.3333 = 7.6667  → solve([7.6667]) → base: false
│   │       │   ├─ op: 0.3333-8 = -7.6667 → solve([-7.6667])→ base: false
│   │       │   ├─ op: 8*0.3333 = 2.6667  → solve([2.6667]) → base: false
│   │       │   ├─ op: (0.3333)/8 ≈ 0.0417→ solve([0.0417]) → base: false
│   │       │   └─ op: 8 / 0.3333 = 24    → solve([24])     → base:
│   │       │                                            abs(24 - 24) ≤ 0.001 → ✅ true (STOP)
│   │       │
│   │       ├─ op: (2.6666)-3 = -0.3333 → solve([8,-0.3333])→ (also fails)
│   │       ├─ op: 3*2.6666 = 8         → solve([8,8])      → (also fails)
│   │       ├─ op: (2.6666)/3 ≈ 0.8889  → solve([8,0.8889]) → (also fails)
│   │       └─ op: 3/(2.6666) = 1.125   → solve([8,1.125])  → (also fails)
│   │
│   └─ op: a=3, b=8 ⇒ a/b = 3/8 = 0.375 → solve([3,8,0.375])→ (also fails)
│
├─ Pair (3,8) [other ordering] … → (also fails)
└─ Pair (8,8) … → (also fails)



*/ 