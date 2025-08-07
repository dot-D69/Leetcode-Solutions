class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int right =0;
        int left =0;
        int maxLen =0;
        unordered_map<int,int>mp;

        while(right<fruits.size()){
            mp[fruits[right]]++;

            if(mp.size()<=2 ){
                maxLen = max(maxLen, right-left+1);
            }
            else{
                mp[fruits[left]]--;

                    if(mp[fruits[left]]==0){
                        mp.erase(fruits[left]);
                    }
                left++;
            }
            right++;
        }
        return maxLen;

    }
};

// The problem is basically finding the largest subarray having two unique windows
// We wiil be using the sliding window algorithm to solve it

/*
 The basic sliding window template is used, with two pointers `left` and `right`  representing the current window's bounds. We also use an unordered_map `mp` to keep track of the count of each fruit type inside the current window.
 Start both pointers at the beginning of the array:
int right = 0;
int left = 0;
int maxLen = 0;
unordered_map<int, int> mp;

// Expand the window by moving `right`:
while (right < fruits.size()) {
    // Add the fruit at `right` to the map and increment its count:
    mp[fruits[right]]++;

    // Now, check if we have exceeded two unique fruit types:
    if (mp.size() <= 2) {
        // We are within valid window limits: update max length if current window is larger.
        maxLen = max(maxLen, right - left + 1);
    } else {
        // Too many fruit types! Need to shrink the window from the left:
        
        // Decrease count of the fruit at `left` pointer as we will move left forward:
        mp[fruits[left]]--;

        // If the count drops to zero, remove that fruit type from `mp` entirely:
        if (mp[fruits[left]] == 0) {
            mp.erase(fruits[left]);
        }

        // Move the left pointer forward to shrink the window:
        left++;
    }

    // Always move right pointer forward to explore new fruits:
    right++;
}

// At loop end, `maxLen` holds the size of the largest subarray containing at most two unique fruits.
// This solves the problem by continuously maintaining a valid sliding window and tracking its maximum size.
return maxLen;
*/