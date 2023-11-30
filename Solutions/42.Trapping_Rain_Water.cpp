class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        if(n==0) return 0;
        int left=0;
        int right=n-1;
        int leftmax=height[left];
        int rightmax=height[right];
        int res=0;

        while(left<right){
            if(leftmax<rightmax){
                left+=1;
                leftmax = max(leftmax,height[left]);
                res+=leftmax-height[left];

            }
            else{
                right-=1;
                rightmax=max(rightmax,height[right]);
                res+=rightmax-height[right];
            }
        }
        return res;
    }
};