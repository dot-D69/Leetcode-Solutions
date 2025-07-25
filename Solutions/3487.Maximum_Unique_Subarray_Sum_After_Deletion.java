class Solution {
    public int maxSum(int[] nums) {
            int sum =0;
            int max_neg= Integer.MIN_VALUE;
            int[] seen = new int[101];

            Arrays.fill(seen,-1);

            for(int n : nums){
                if(n<=0){
                    max_neg = Math.max(max_neg,n);

                }
                else{
                    if(seen[n]==-1){
                    sum+=n;
                    seen[n] = 1;
                    }
                }
            }
        return sum ==0 ? max_neg: sum;
    }
}