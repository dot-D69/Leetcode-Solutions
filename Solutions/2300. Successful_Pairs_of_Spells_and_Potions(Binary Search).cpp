//Implement LowerBound
class Solution {
public:
    int lowerBound(int l ,int r,vector<int>& potions,int target){
        int ans = 0;
        while(l<=r){
           int mid=l+(r-l)/2;
            if(potions[mid]>=target){
                ans = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }



    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();

        sort(potions.begin(),potions.end());// We sort the potion as it becomes easier to search for the value that will be greater than or equal to the success
        //If the potions is sorted and we find the min vale for which the product is greater that or equal to success then we don't have to check for others as every element pass that point will also be greater than our success, that is why sorting is needed

        vector<int> res;
        int maxVal = potions[n-1]; //since sorted the the end p  poitins will have the maximum value of the potions array, which we will use further for

//We iterate over spells array
        for(int i =0;i<m;i++){
            int spell = spells[i];

            //spell * Potion >=success  
            //Potion>=success/spell     and we need the ceil value so we need to convert this into float
            //Potion>=(1.0*success)/spell

            long long potion = ceil(1.0*success/spell);

            if(potion>maxVal){
                res.push_back(0);
                continue;
            }

            int idx = lowerBound(0,n-1,potions,potion); 
            //This gives us the index for the element in potions array that is greater than or equal to our potion value, since every element after that point will be greater than success so we just need to find this index

            int count = n-idx;
            res.push_back(count);
        }

        return res;
    }
};