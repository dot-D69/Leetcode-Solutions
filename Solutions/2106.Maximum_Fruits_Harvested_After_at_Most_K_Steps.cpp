class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxFruits =0;

        // We have to use upper and lower bound so we need a plain vector to apply that
        vector<int> position(n); //  stores the positions
        vector<int> prefixSum(n); //  stores the prefix sum so that later we can get the sum of fruits within position

        // Populate the vectors
        for(int i=0;i<n;i++){
            position[i] = fruits[i][0]; // Since frutis a 2d vector so [i][0]-> this means the first col of each row which have the psotions in them
            if(i>0){
                prefixSum[i] = fruits[i][1]+prefixSum[i-1];
            }
            else{
                prefixSum[i] = fruits[i][1];
            }
            
        }

    

        // After populating we will go to the cases in which we move there are two cases.
        // we first move left and then go right if we move from startPos(P) to left so say we moved 'd' steps, then we come back to the starPos(P), 
        // so till now the remainng steps are K-2d -> How : first we moved to left then remaininsteps = K-d, then we came back to P , meaning we moved d more steps ,therefore remainingsteps= k-2d
        // Now we can move to right but only P+K-2d steps
        // (The plus and minus happens acc. to direction of movement since we are x axis if we move left so we subtract and if we move right we add)
        // The value of d : k-2d >=0 ---> 2d<=k ----> d<= k/2

        for(int d=0;d<=k/2;d++){
            // Case 1: first move to left , then only move to right ( no coming back to left)
            int i = startPos - d;
            int remainingSteps = k-2*d;
            int j = startPos+remainingSteps;

            int left = lower_bound(position.begin(),position.end(), i) - position.begin(); // what does it do , this is nothing but b8inary search, the code behing lower_bound is also of binary search it works in the same way. Lower_bound will return the element >= i(or the element passed)
            int right = upper_bound(position.begin(),position.end(), j) - position.begin()-1; // upper boundw will return element > j( it skips all equal element )
            // Here we are doing -1 because upperbound will give element greater than j, we don't want greater than j, we want either equal to j or less than when we subtract -1 so it will then gives the j( since upper bound only give the element just greater than j )


// Now since we have gotten our window of points we have moved so now we will get the total number of fruits for that particular window
// we were storing the prefixsum for each position 
// now if we want the prefix sum for left to right : we wiil have to prefixSum[right] - prefixSum[left-1];
// Eg: [8,3,6,4]---> now if you want the sum from index 1 to index 3(i.e 3+6+4 = 13)
// prefixSum = [8,11,17,21] ---> 21 - 8 = 13 (we need to subtract one more index than the required to get oru deisre answer)
        if(left<=right){// To check while doing binary search , left is not out of bound
        int total =0;
           if(left>0){
            total = prefixSum[right] - prefixSum[left-1]; 
           }
           else{
            total = prefixSum[right];
           }

           maxFruits = max(maxFruits,total);
        }

        //Case 2: move right then move left
        j= startPos+d;
        i = startPos - remainingSteps; 
        // remaining steps will stiil wil be k-2*d, so noo nedd to writ them again

        left = lower_bound(position.begin(),position.end(), i) - position.begin(); 
        right = upper_bound(position.begin(),position.end(), j) - position.begin()-1;

        if(left<=right){// To check while doing binary search , left is not out of bound
         int total =0;
           if(left>0){
            total = prefixSum[right] - prefixSum[left-1]; 
           }
           else{
            total = prefixSum[right];
           }

           maxFruits = max(maxFruits,total);
        }

        }

        return maxFruits;
    }
};