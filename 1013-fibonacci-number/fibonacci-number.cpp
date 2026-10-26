class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0; 
        if (n == 1) return 1;
	    int secondLast = 0;
	    int last = 1;
        int cur;
	    for (int i = 2; i <= n; i++) {
		    cur = last + secondLast;
    		secondLast = last;
	    	last = cur;
        }
    return cur; 
    }  
};