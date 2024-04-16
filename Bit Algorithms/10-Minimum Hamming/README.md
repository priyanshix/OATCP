# Minimum Hamming

## Algorithm
- The algorithm iterates through each bit position from the least significant bit to the most significant bit (from 0 to 31 for a 32-bit integer).
- At each bit position, it counts the number of ones and zeros among all integers in the vector.
- The pairwise Hamming distance contribution for that bit position is calculated by multiplying the counts of ones and zeros.
- Finally, it accumulates these contributions for all bit positions to obtain the total Hamming distance.

Using a bitwise approach allows the algorithm to efficiently process each bit of the integers in the vector, leading to an optimized solution for calculating the total Hamming distance.

## Time Complexity: O(n), Space Complexity: O(1)
