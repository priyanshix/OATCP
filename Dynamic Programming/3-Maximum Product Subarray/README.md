### Algorithm:
- Initialize variables to store the maximum product, minimum product, and final result.
- Iterate through the input array, updating the maximum and minimum products considering the current element.
- Swap the maximum and minimum products if the current element is negative.
- Update the final result with the maximum product seen so far.
- Return the final result as the maximum product of a subarray.
- Let maxProd[i] represent the maximum product of a subarray ending at index i, and minProd[i] represent the minimum product of a subarray ending at index i. Then, the recursive formulas are:
```maxProd[i] = max(nums[i], maxProd[i-1] * nums[i], minProd[i-1] * nums[i])```  
```minProd[i] = min(nums[i], maxProd[i-1] * nums[i], minProd[i-1] * nums[i])```  
Where:  
max(nums[i], maxProd[i-1] * nums[i], minProd[i-1] * nums[i]) calculates the maximum product by considering the current element, multiplying it with the maximum product of the previous subarray, and multiplying it with the minimum product of the previous subarray.  
min(nums[i], maxProd[i-1] * nums[i], minProd[i-1] * nums[i]) calculates the minimum product in a similar manner.
The final answer is the maximum value in the maxProd array, which represents the maximum product of any subarray within the input array.

### Overlapping Subproblem:
- The algorithm recalculates maximum and minimum products for each element, potentially revisiting subproblems.
### Optimal Substructure:
- Finding the maximum product of a subarray can be achieved by solving smaller subproblems, leading to an optimal solution.

### Time Complexity : O(N), Space Complexity : O(1)
