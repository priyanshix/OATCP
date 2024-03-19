### Algorithm:
1. Read input values `n`, `a[]`, `m`, and `b[]` from the input file.
2. Sort arrays `a[]` and `b[]`.
3. Initialize a 2D array `dp[][]` of size `n x m`.
4. Iterate over indices `i` from 0 to `n-1` and `j` from 0 to `m-1`:
   - Check if `(i-1, j-1)` is within bounds and update `dp[i][j]` with `max(dp[i][j], dp[i-1][j-1])`.
   - If the absolute difference between `a[i]` and `b[j]` is less than or equal to 1, increment `dp[i][j]`.
   - If `(i-1, j)` is within bounds, update `dp[i][j]` with `max(dp[i][j], dp[i-1][j])`.
   - If `(i, j-1)` is within bounds, update `dp[i][j]` with `max(dp[i][j], dp[i][j-1])`.
5. Write the value of `dp[n-1][m-1]` to the output file.

### Optimal Substructure
- The optimal substructure property holds because the optimal solution for the entire array can be derived from the optimal solutions of smaller subarrays. The maximum number of pairs can be formed at any position `(i, j)` based on the maximum number of pairs formed at positions `(i-1, j-1)`, `(i-1, j)`, and `(i, j-1)`.

### Overlapping Subproblem
- Overlapping subproblems occur because the same subarray computations are performed multiple times. For example, when calculating `dp[i][j]`, we rely on the values of `dp[i-1][j-1]`, `dp[i-1][j]`, and `dp[i][j-1]`, which may have already been computed. This recurrence relationship leads to redundant calculations, making the problem exhibit overlapping subproblems.
