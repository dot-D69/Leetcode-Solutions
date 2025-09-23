//Two Pass Solution
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n  = nums.size();
        int freq = 0;
        int cnt =0;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
            freq = max(freq,mp[nums[i]]);
        }
    
        for(auto &it :mp){
            if(it.second==freq){
                cnt+=freq;
            }

        }
        return cnt;
    }
};


//--------------------------------------------------------------------------------------------------------------------


//One Pass Solution
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n  = nums.size();
        int maxfreq = 0;
        int cnt =0;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
            int freq = mp[nums[i]];

            if(freq >maxfreq){
                maxfreq= freq;
                cnt = maxfreq;
            }
            else if(freq == maxfreq){
                cnt+=maxfreq;
            }
        }
    
        return cnt;
    }
};