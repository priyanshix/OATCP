# Smallest Integer

## Algorithm: 
- The algorithm used is a greedy approach. It iterates over the digits of the input number (`num`). 
- For each digit, it compares it with the last digit in the result (`res`). 
- If the current digit is smaller and there are still remaining removals (`k`), it removes the last digit from the result until it finds a smaller digit or until `k` is exhausted. 
- It also removes leading zeros from the result. 
- After the iteration, if there are still removals left (`k > 0`), it removes the last `k` digits from the result.

## Time Complexity : O(n), Space Complexity: O(n)
