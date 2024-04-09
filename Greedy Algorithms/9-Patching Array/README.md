# Patching Array

## Algorithm
- Initialize variables to track the current range covered by the array and the number of patches required. Set the initial range to [1,1] and patches count to 0.
- Iterate through the input array. For each element in the array, compare it with the current upper bound of the range. If the element is within the current range, extend the range to include it. If the element exceeds the current upper bound, patch the array by doubling the range and incrementing the patches count until the element is covered.
- Update Range: If the current element is within the range, extend the range to include it by adding the element to the current upper bound. Move to the next element in the array.
- If the current element exceeds the range, patch the array by doubling the current range and incrementing the patches count. Keep doubling the range until it covers the current element.
- Repeat steps 3 and 4 until the range covers the target value 'n'. Once the range covers 'n', return the number of patches required to achieve the desired array.

## Time Complexity: O(n), Space Complexity: O(1)