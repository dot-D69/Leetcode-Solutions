//Using array Simulation
class Solution {
public:

    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }

    //We use i =0 , since we would be traversing the arr, and it starts fromthe first element
        int i =0; 

        while(arr.size()>1){
// idx is the element to delete , the i+k-1 comes from : if i=0 thenwe would have to deletee i =1 (as count reaches 2 including the element at i=0) for i=0, we delete i=1, for i =2 we delte i=3.we can put that into a formula that is         : i+k-1            
            int idx = (i+k-1)%arr.size(); //We use % arr.size() as for values that are out of index we need to wrap around
            arr.erase(arr.begin()+idx);//This removes the element at idx an moves all other elements to front takes O(n)

            i = idx;
        }
        //When it comes out of the while loop it means that we only have one element in our arr since arr.size() became < 1
        
        return arr[0];
    }
};