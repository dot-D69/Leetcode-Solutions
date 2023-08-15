class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int i =0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        for(int j=1;j<k;j++){
            pq.pop();
        }

        return pq.top();
    }
};


// Time Complexity : O(nlogk)
// Space Complexity : O(k)


// Explanation:

// 1.)  a priority queue pq of integers is initialized. This data structure automatically arranges elements in a way that the highest value resides at the top.

// 2.) The for loop is used to push all the elements of the vector nums into the priority queue pq. using push() function.

// 3.) After inserting all elements into the priority queue, a loop is used to remove k-1 largest elements from the top of the queue. This is done using the pop() function.

    /*3.1) The priority queue, acting as a max heap, organizes its elements such that the largest element is always at the top (root) of the heap.
    
    When elements are inserted into the priority queue in this code, they are automatically arranged in descending order. This means that the largest element in the input data will be at the top of the priority queue.

    The goal is to find the kth largest element. To achieve this, the code iteratively removes elements from the top of the priority queue (which are the largest elements) using the pop operation.

    By performing the pop operation k-1 times, the code effectively eliminates k-1 largest elements from consideration. What remains at the top of the priority queue is the kth largest element, which is the desired outcom
    */

    // 4.) Upon completing the removal loop, the kth largest element remains at the top of the priority queue. This is accessed using the top method..
