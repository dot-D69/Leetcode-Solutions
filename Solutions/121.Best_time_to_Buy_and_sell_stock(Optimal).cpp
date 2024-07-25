class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_till=prices[0];
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            min_till=min(prices[i],min_till);
            int profit=prices[i]-min_till;
            maxprofit=max(profit,maxprofit);
        }
        return maxprofit;
    }
};

// The logic behind this code is that we are finding the previous minimum element so far as we are in the array

// So every time we move forward we check if the current element is the minimum then previous elements so far

// and on everyday we check for the profit we will make if we sell by subtracting the current element from the minimum element

//e.g : 7 ,1,5,3,6,4
//at first our min is set at prices[0] i.e 7
//then we check if the curr ele - min and store it in profit i.e. 7-7 =0
//maxprofit remains 0

//then we come to the second day and check if the element is less than the min , it is so we update the min i.e min=1
// again curr ele -min i.e 1-1 =0;
// maxprofit=0;

// on the 3rd day we again check if the curr ele is less than min, it is not
// curr ele - min i.e. 5-1 = 4
// max profit is updated to 4 (as 4 is greater than 0)

//4th day , curr_ele >min
// curr_ele-min i.e 3-1 =2
//maxprofit =4;

//5th day, curr_ele>min
//curr_elemin i.e. 6-1=5
//maxprofit is updated = 5(since 5 is greater than 4)


//6th day , curr_ele >min
// curr_ele-min i.e 4-1 =3
//maxprofit =5;

//at last we return the max profit that is 5;


//The logic is to check for the minimum element so far for which when we sell will generate the maxprofit
