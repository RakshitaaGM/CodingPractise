//You are climbing a staircase. It takes n steps to reach the top.

//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Hint : Fibonacci
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2)
            return n;
        int arr[n + 1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        for(int i = 3 ; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
         
    }
};

// Saves space
int pprev, prev, curr;
        pprev = 1; prev = 2;
        for(int i = 3; i <= n; i++ )
        {
            curr = pprev + prev;
            pprev = prev;
            prev = curr;
        }
         return curr;