#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n=arr.size();
        stack<int> s1,s2;
        vector<int> left(n),right(n);
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>=arr[i] ){
                s1.pop();
            }
            if(!s1.empty()){
                left[i]=s1.top();
            }
            else{
                left[i]=-1;
            }
            s1.push(i);
        }
        
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]>=arr[i] ){
                s2.pop();
            }
            if(!s2.empty()){
                right[i]=s2.top();
            }
            else{
                right[i]=-1;
            }
            s2.push(i);
        }
        
        
        for(int i=0;i<n;i++){
            if(left[i]==-1 && right[i]==-1){
                ans[i]=-1;
            }
            else if(left[i]==-1){
                ans[i]=right[i];
            }
            else if(right[i]==-1){
                ans[i]=left[i];
            }
            else{
                if(abs(i-left[i])>abs(i-right[i])){
                    ans[i]=right[i];
                }
                else if(abs(i-left[i])<abs(i-right[i])){
                    ans[i]=left[i];
                }
                else if(arr[left[i]]<=arr[right[i]]){
                    ans[i]=left[i];
                }
                else{
                    ans[i]=right[i];
                }
            }
        }
        return ans;
        
    }
};
