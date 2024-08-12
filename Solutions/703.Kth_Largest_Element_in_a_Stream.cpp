class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> pq;  // min heap (defined globally so as to be accessible)
int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int &i :nums){
            pq.push(i);

            if(pq.size()>K){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size()>K){
                pq.pop();
        }

        return pq.top();
    }
};
