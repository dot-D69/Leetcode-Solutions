//Using queue simulation 
class Solution { public: int findTheWinner(int n, int k) { 
    queue<int> que; 
    for(int i=1;i<=n;i++){ 
        que.push(i); } 
        while(que.size()>1){
             for(int count =1;count<=k-1;count++){ //We oush the first k-1 elements to the back so we can get the Kth element at the front of the queue o to removwe it 
             que.push(que.front()); 
             que.pop(); 
            } 
            que.pop(); // This pops the element presetn at the front after pushing k-1 elements to the back i.e. the Kth element being removed 
        } 
        return que.front(); 
    } 
};


/*

Initial queue (front -> back):
[1, 2, 3, 4, 5]

Iteration 1:
 rotate k-1 = 1 times:
  push front 1 to back -> queue becomes [2, 3, 4, 5, 1]
 remove front (kth) -> remove 2 -> queue becomes [3, 4, 5, 1]

Iteration 2:
 rotate 1 time:
  push front 3 to back -> queue becomes [4, 5, 1, 3]
 remove front (kth) -> remove 4 -> queue becomes [5, 1, 3]

Iteration 3:
 rotate 1 time:
  push front 5 to back -> queue becomes [1, 3, 5]
 remove front (kth) -> remove 1 -> queue becomes [3, 5]

Iteration 4:
 rotate 1 time:
  push front 3 to back -> queue becomes [5, 3]
 remove front (kth) -> remove 5 -> queue becomes [3]

End:
 queue size == 1 -> Winner = 3


*/