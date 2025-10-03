//Simulation Approach
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;// Start by drinking all the full bottles
        int empty = drank;  // All those bottles we drank are now empty

        while(empty>=numExchange){ // Keep exchanging as long as we have enough empties
            drank++; // Drink the bottle we get from the exchange
            empty = empty-numExchange + 1; // Remove exchanged empties, add the new empty
            numExchange++; // Exchange rate increases after each trade
        }
        return drank; // Return total bottles drunk
    }
};


/*
We start by drinking all the full bottles we have initially.
drank keeps track of the total bottles drunk so far.

All those bottles are now empty, so empty equals the number we just drank.

We keep looping as long as we have enough empties to make at least one exchange.

Here’s the subtle part:

empty - numExchange → remove the empties we gave for the exchange.
+ 1 → add the empty from the bottle we just drank, the one that we got after exchange.

Increase the count of NumExchange after every exchange

The loops ends when the mepty bottles are less than exchange rate 





Time Complexity: O(k) where k is the number of exchanges possible before empties < numExchange.
Since numBottles and numExchange are ≤ 100, worst case is small — practically O(1) for constraints.
Space complexity: O(1) 

*/