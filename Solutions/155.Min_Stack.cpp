class MinStack {
    stack<long> s;
	long  mini;
public:
    MinStack() {
        mini=INT_MAX;	
    }
    
    void push(int val) {
        long num =val ;
			if(s.empty()){
				mini=num;
				s.push(num);
			}
			else{
				if(num<mini){
					s.push(2*num*1L- mini); // using the formula to encode  the minimum  2*value-minimum so that when we pop the minimum we are able to revisit to thee prev minimum 
					mini=num;
				}
				else{
					s.push(num);
				}
			}
    }
    
    void pop() {
        if(s.empty()) return ;
			long x = s.top();
			s.pop();
			
			if(x<mini){
				mini = 2*mini-x; // here we are going to the prevminimum 
			}
        
    }
    
    int top() {
        if(s.empty()) return -1;

			long x = s.top();
			if(x<mini) return mini;
			
			return x;
    }
    
    int getMin() {
        if(s.empty()) return -1;
			return mini;
    }
};
