class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>v1(101),v2(101),v3(101),ans;

        for(int i =0;i<nums1.size();i++){
            v1[nums1[i]]=1;
        }

        for(int i =0;i<nums2.size();i++){
            v2[nums2[i]]=1;
        }

        for(int i =0;i<nums3.size();i++){
            v3[nums3[i]]=1;
        }
        
        for(int i =0;i<=100;i++){
            if(v1[i]+v2[i]+v3[i]>=2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};