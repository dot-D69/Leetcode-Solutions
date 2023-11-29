class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) { 
        stack<int> st;
        for(int &a: asteroids){
            while(!st.empty()&& a<0 && st.top()>0) // Condition for collision
            {
                int sum=a + st.top();

                if(sum<0){
                    st.pop(); // the positve asteroid is destroyed
                }
                else if(sum>0){
                    a=0; // The negative asteroid is destroyed and when a becomes 0 it does satisfy and hence breaks out of while loop 
                }
                else{ //both are of same size
                    st.pop();
                    a=0;
                }
            }
            if(a!=0){
                st.push(a);
            }   
        }


        int n = st.size();
        vector<int> res(n);

        for(int i=n-1;i>=0;i--){
            res[i]=st.top();
            st.pop();
        }
        
        return res;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

// If the asteroid array also had 0 as input then we have to change only  little bit when ishing in the stack
// if(a!=0 || st.empty()||st.top<0){
//     st.push(a);
// }