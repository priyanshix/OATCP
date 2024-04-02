# Dice Combination

## Algorithm
- Initialize a dynamic programming array `dp[]` where `dp[i]` represents the number of ways to obtain sum `i`.
- Set `dp[0] = 1` as there's only one way to get a sum of 0.
- Iterate through each index `i` from 1 to `n`.
- For each index `i`, iterate through integers from 1 to 6.
- Update `dp[i]` by adding the number of ways to obtain the current sum `i` by using the sum `i-j` for each integer `j` from 1 to 6.
- Return `dp[n]`, representing the number of ways to obtain the desired sum.
