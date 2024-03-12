### Algorithm:
⚫Create an array DP if size 6 instead of size N because we need only the previous 6 computations to get the current value.
⚫Initialize DP with base case dp[0] = 1.
⚫Iterate over subproblems and get the current value from previous solutions of subproblems stored in DP.
⚫At the last return, the final answer is stored in dp[N%6]. ( n%6 ) to compute only the last 6 values.
