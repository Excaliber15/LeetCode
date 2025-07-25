class Solution {
public:
    int solve(int n){
        // base cases
        if(n==0 || n==1) return n;
        // RE
        return solve(n-1)+solve(n-2);
    }
    int fib(int n) {
        int ans=solve(n);
        return ans;
    }
};