#include<bits/stdc++.h>
using namespace std;

    int majorityelement(vector<int>& nums){
        int n = nums.size();
        unordered_map<int,int> map;
        for(auto a:nums){
            map[a]++;
            if(map[a]>n/2){
                return a;
            }
        }
        return -1;
    }