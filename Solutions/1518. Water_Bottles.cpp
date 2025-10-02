class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = numBottles; // Start by drinking all initial full bottles

        // Continue as long as we have enough empty bottles to exchange
        while (numBottles >= numExchange) {
            drank += numBottles / numExchange; // Exchange as many as possible and drink them
            int newfull = numBottles / numExchange; // Full bottles from exchange
            int left = numBottles % numExchange;    // Empties left after exchange
            numBottles = newfull + left; // New total bottles (full + leftover empties)
        }

        return drank; // Return total bottles drunk
    }
};

// Time Complexity: O(k) where k = number of exchanges (bounded by constraints → effectively O(1))
// Space Complexity: O(1) → only a few integer variables