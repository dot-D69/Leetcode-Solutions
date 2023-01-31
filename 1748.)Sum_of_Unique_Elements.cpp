class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

        std::unordered_map<int, int> frequency;
        for(int num :nums){
            if(frequency.count(num) == 0){
                frequency[num] = 0;
            }
            frequency[num]++;
        }
        
        int sum =0;
        for (auto it = frequency.begin(); it != frequency.end(); it++){
            if(it->second == 1){
                sum+= it->first;
            }
        }
        return sum;
    }
};