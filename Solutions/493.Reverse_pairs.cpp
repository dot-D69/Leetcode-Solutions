class Solution {
public:

    int count(vector<int>&arr,int low, int mid, int high ){
    int right = mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
        while (right <= high && static_cast<long long>(arr[i]) > 2 * static_cast<long long>(arr[right])) {
        right++;
    }
        cnt+=(right-(mid+1));
    }
    return cnt;
}

    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
                temp.push_back(arr[left]);
                left++;
            }

            //  if elements on the right half are still left //
            while (right <= high) {
                temp.push_back(arr[right]);
                right++;
            }

            // transfering all elements from temporary to arr //
            for (int i = low; i <= high; i++) {
                arr[i] = temp[i - low];
            }
    }



int mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return 0;
    int COUNT =0;
    int mid = (low + high) / 2 ;
    COUNT+=mergeSort(arr, low, mid);  // left half
    COUNT+=mergeSort(arr, mid + 1, high); // right half
    COUNT+=count(arr,low,mid,high);
    merge(arr, low, mid, high);  // merging sorted halves
    return COUNT;
}

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};


// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// Explanation can be found on  https://www.youtube.com/watch?v=0e4bZaP3MDI&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F&feature=emb_imp_woyt