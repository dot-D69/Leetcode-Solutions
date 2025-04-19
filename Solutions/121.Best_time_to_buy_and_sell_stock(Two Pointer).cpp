class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int left =0;
            int right = 1;
            int profit =0;
    
            while(right<prices.size()){
    
                if(prices[left]<prices[right]){
                    int diff = prices[right] -prices[left];
                    profit = max(profit,diff);
                }
                else{
                    left = right;
                }
                right++;
            }
            return profit;
        }
    };