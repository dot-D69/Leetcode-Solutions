//Aggressive Cows approach

class Solution {
public:
    bool isPossible(vector<int>& position,int dist,int m){
        int numofballs=1,lastpos=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-lastpos>=dist){
                numofballs++;
                lastpos=position[i];
            }
        }
        return(numofballs>=m);
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=0,high=position[n-1];
        int ans=1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(position,mid,m)==true){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};