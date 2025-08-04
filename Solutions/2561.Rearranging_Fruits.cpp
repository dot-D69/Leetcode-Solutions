class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int min_ele= INT_MAX;

        for(const int &it : basket1){
            mp[it]++;
            min_ele = min(it,min_ele);
        }

        for(const int &it: basket2){
            mp[it]--;
            min_ele = min(it,min_ele);
        }

        vector<int> repeatList;
        for(auto &x:mp){  // we use auto so there is no type mismatch as map will return a pair of key and value
            int cost = x.first;
            int freq = x.second;

            if(freq==0){
                continue;
            }
            
            if(freq%2!=0){
                return -1;
            }

            for(int i =1;i<=abs(freq)/2;i++){
                repeatList.push_back(cost);
            }
        }

        // Sorting
        sort(repeatList.begin(), repeatList.end());

        long long res =0;
        for(int i=0;i<repeatList.size()/2;i++){
            res+= min(repeatList[i], min_ele*2); 
        }
        return res;
    }
};


/*

Step-by-step Explanation:
1. Counting fruit imbalances:

First, the code creates a map mp that counts the difference in fruit quantities between the two baskets.

It iterates over basket1 and for each fruit increases the count in mp.

Then, it iterates over basket2 and for each fruit decreases the count in the same map.

After these passes, mp tells us:

Which fruits are "extra" in basket1 (positive count),

Which are "extra" in basket2 (negative count),

And which fruits are balanced (count zero).

Also, during these iterations, the code keeps track of the smallest fruit value seen, called min_ele. This is important later because swapping the smallest fruit twice might sometimes cost less than swapping some bigger fruits directly.

2. Checking feasibility:

The next step is to make sure it is possible to rearrange the baskets to be identical.

For rearrangement to be possible:

Each fruit's imbalance count (freq) must be even because you can only swap fruits in pairs.

If any fruit count is odd, it’s impossible to fix the mismatch by swapping pairs, so the function returns -1.

3. Preparing the list of fruits to swap:

For every fruit with a non-zero even imbalance, the code adds half of those extra fruits (absolute count divided by two) into a list called repeatList.

This list represents the fruits that need to be swapped because they appear “extra” in one basket.

The size of this list will be exactly the number of swaps required (since every swap fixes two imbalances, one in each basket).

4. Sorting fruits by cost:

The list repeatList is then sorted so the cheapest fruits come first.

Minimizing the cost of swaps means you want to focus on swapping the cheapest fruits first.

But there's a twist! Swapping might be cheaper if you swap the smallest fruit twice rather than swapping more expensive fruits directly.

5. Calculating minimal swap cost:

The code then iterates over just the first half of the repeatList (since each swap involves two fruits, we consider half the list for the number of swaps).

For each fruit in this half, it adds to the result the minimum cost between:

Swapping this fruit directly (cost = fruit’s value),

Or swapping the smallest fruit twice (cost = 2 * min_ele).

This clever trick ensures that if swapping through the smallest fruit is cheaper, it chooses that path, resulting in a lower total cost.

6. Returning the answer:

Finally, the total minimum cost res is returned, representing the least amount of money needed to make the two baskets identical by swapping fruits.



*/