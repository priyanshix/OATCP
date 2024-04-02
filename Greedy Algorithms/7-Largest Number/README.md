# Largest Number

## Algorithm
- Read integers from the input file into a vector.
- Convert each integer to a string and store them in another vector.
- Sort the vector of strings in non-decreasing order using a custom comparison function.
- Concatenate the strings to form the largest possible number.
- If the resulting number starts with '0', return "0" as the largest number.
- Otherwise, return the concatenated string as the largest number.

### Time Complexity: O(n log n), Space Complexity: O(n)
